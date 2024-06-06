# 컴파일러
CXX = g++

# 컴파일 플래그
CXXFLAGS = -Wall -Wextra -std=c++11

# 링커 플래그
LDFLAGS = -lncurses

# 소스 디렉토리
SRC_DIR = src

# 소스 파일
SRCS = $(SRC_DIR)/Board.cpp $(SRC_DIR)/Snake.cpp $(SRC_DIR)/SnakeGame.cpp main.cpp

# 오브젝트 파일
OBJS = $(SRCS:.cpp=.o)

# 실행 파일 이름
TARGET = snake_game

# 기본 타겟
all: $(TARGET)

# 실행 파일 생성 규칙
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# 각 .cpp 파일을 .o 파일로 컴파일하는 규칙
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean 규칙
clean:
	rm -f $(OBJS) $(TARGET)

# makefile이 dependencies를 자동으로 추적하도록 합니다
-include $(OBJS:.o=.d)

# 각 .cpp 파일에 대한 dependencies 파일(.d)을 생성합니다
%.d: %.cpp
	@$(CXX) $(CXXFLAGS) -M $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
