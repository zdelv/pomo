# fmt : 
# 	clang++ include/fmt/format.cc

pomo : 
	clang++ --std=c++17 -I./include -pthread -o build/pomo src/main.cpp

pomov :
	clang++ -v --std=c++17 -I./include -pthread -o build/pomo src/main.cpp

clean :
	rm build/pomo
