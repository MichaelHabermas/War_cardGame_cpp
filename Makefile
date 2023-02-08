app: main.cpp Game.cpp InputManager.cpp StateMachine.cpp AssetManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp Card.cpp
	g++ -w -o app -std=c++11 -lsfml-system -lsfml-graphics -lsfml-window main.cpp Game.cpp InputManager.cpp StateMachine.cpp AssetManager.cpp SplashState.cpp MainMenuState.cpp GameState.cpp Card.cpp

clean: ./app
	rm ./app

toolchain:
	which -s brew
	if [[ $? != 0 ]] ; then
		/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
	fi
	brew install sfml

fullRun:
	make clean && make app && ./app
	