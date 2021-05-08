#! /bin/bash
if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    case "$(uname -s)" in
    Darwin|Linux)
    DOS2UNIX="sed -e s/\r//g"
    ;;

    *)
        # This works on a GNU version of sed. I think this
        # will work in OSX as well, but don't have a machine
        # on which to test that. From reading the OSX docs,
        # it looks compatible.
        # The code \x0D is the ASCII code of carriage-return,
        # so it the regex should delete any CRs at the end of
        # a line (or anywhere in a line)
      DOS2UNIX="cat"
	# Tested for combinations of:
	# - Ubuntu
	# - Cygwin
	# and inputs formats:
	# - LF
	# - CRLF
    ;;
    esac
fi

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building compiler"
make bin/c_compiler -B #unconditionally make all target
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
    exit 1;
fi
sed -i -e 's/\r$//' bin/c_compiler
echo "========================================="
PASSED=0
CHECKED=0
for folder in compiler_tests/*; do
  echo "Folder: ${folder}"
  BASEFOLDER=$(echo "$folder" | cut -f 2 -d '/')

  for file in "$folder"/*_driver.c; do
    name="${file%%_driver*}"
    BASE=$(echo "$name" | cut -f 3 -d '/')
  for i in "$name".c; do
    RETURN=$?
    echo ""
    mips-linux-gnu-gcc -mfp32 -static -o out "$name".c "$name"_driver.c
    qemu-mips out
    echo "Producing ref files, NO DIFF YET..."
    echo "$RETURN" > test/ref/"$BASEFOLDER"/"$BASE".s
    done
  done

echo ""

  for compil in "$folder"/*_driver.c; do
  name="${compil%%_driver*}"
  echo "INPUT COMPILER TEST: ${name}"
  BASE=$(echo "$name" | cut -f 3 -d '/')
    for i in "$name".c; do
        echo "==========================="
        echo ""
        echo "Input file : ${i}"
        bin/c_compiler -S "$name".c -o out.s
        mips-linux-gnu-gcc -mfp32 -o out.o -c out.s
        mips-linux-gnu-gcc -mfp32 -static -o out out.o "$name"_driver.c
        qemu-mips out
        RETURN=$?
        echo "Producing out files ..."
        echo "$RETURN" > test/out/"$BASEFOLDER"/"$BASE".s
        if cmp -s test/ref/"$BASEFOLDER"/"$BASE".s test/out/"$BASEFOLDER"/"$BASE".s
        then
        echo "\nRef and Output are identical"
        PASSED=$(( ${PASSED}+1 ));
        else
            echo -e "\nERROR"
        fi
        CHECKED=$(( ${CHECKED}+1 ));
    done

  done
  echo "DONE"
echo "========================================="
done
echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""
case "$(uname -s)" in
    Darwin)
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    exit 0
    ;;
esac

RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 16.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi