app: main.cpp Game.cpp InputManager.cpp StateMachine.cpp AssetManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp Card.cpp
	g++ -w -o app -std=c++11 -lsfml-system -lsfml-graphics -lsfml-window main.cpp Game.cpp InputManager.cpp StateMachine.cpp AssetManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp Card.cpp

clean: ./app
	rm ./app

toolchain:
	brew install sfml