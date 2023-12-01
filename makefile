COURSE = cs310
SEMESTER = fall2023
CP_NUMBER = 4
LASTNAME = group16
GITUSERID = group16
EXE = actor_db
MENU_EXE = menu_sample

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = ../CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar
ZIPFILE = $(TARFILE).gz

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -Wextra -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/movie_db.o $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/ActorHeap.o $(OBJ)/ActorBST.o $(OBJ)/Array.o
	$(CC) $(FLAGS) $(OBJ)/movie_db.o $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/ActorHeap.o $(OBJ)/ActorBST.o $(OBJ)/Array.o -o $@

$(OBJ)/movie_db.o: movie_db.cpp Parser.h
	$(CC) $(FLAGS) -c movie_db.cpp -o $@

$(OBJ)/ActorDB.o: ActorDB.cpp ActorDB.h Actor.h ActorHeap.h ActorBST.h Array.h
	$(CC) $(FLAGS) -c ActorDB.cpp -o $@


# $(OBJ)/Movie.o: Movie.cpp Movie.h Actor.h
# 	$(CC) $(FLAGS) -c Movie.cpp -o $@

$(OBJ)/Actor.o: Actor.cpp Actor.h
	$(CC) $(FLAGS) -c Actor.cpp -o $@
	
$(OBJ)/ActorHeap.o: ActorHeap.cpp ActorHeap.h Actor.h
	$(CC) $(FLAGS) -c ActorHeap.cpp -o $@

$(OBJ)/ActorBST.o: ActorBST.cpp ActorBST.h Actor.h
	$(CC) $(FLAGS) -c ActorBST.cpp -o $@

$(OBJ)/Array.o: Array.cpp Array.h
	$(CC) $(FLAGS) -c Array.cpp -o $@
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)
	@echo "Tarred and gzipped file is in the directory one level up"
	@echo $(ZIPFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) $(ZIPFILE)
