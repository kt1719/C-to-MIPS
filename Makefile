
CPPFLAGS += -std=c++17 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

bin/c_compiler : bin/compiler src/wrapper.sh
	cp src/wrapper.sh bin/c_compiler
	chmod u+x bin/c_compiler

bin/compiler : src/compiler.cpp src/lexer.cpp src/parser.tab.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/compiler $^

src/lexer.cpp : src/lexer.flex src/parser.tab.hpp
		flex -o src/lexer.cpp  src/lexer.flex

src/parser.tab.cpp src/parser.tab.hpp: src/parser.y
		bison -v -d src/parser.y -o src/parser.tab.cpp

clean :
	rm -f src/*.o
	rm -f *.cpp
	rm test/out/*/*.s
	rm test/ref/*/*.s
	@echo "Clean Done."
