#OBJS specifies which files to compile as part of the project
OBJS = StateMachine.cpp Main.cpp Audio.cpp  Btimer.cpp  Launch.cpp MoveCharacter.cpp Character.cpp Circle.cpp CollisionDetector.cpp ExitState.cpp  Newton.cpp   Object.cpp Physics.cpp Renderer.cpp Scene.cpp Texture.cpp LoadCollisionMap.cpp 
CC =g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer 
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = fisica 
#This is the target that compiles our executable 
all : $(OBJS) 
	g++ $(OBJS) -w $(LINKER_FLAGS) -o $(OBJ_NAME)
