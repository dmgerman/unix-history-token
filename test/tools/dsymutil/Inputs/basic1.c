begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is the main file used to produce the basic* objects that are    used for the dsymutil tests.     These are compiled in a couple of different ways (always on a    Darwin system):    Basic compilation:       for FILE in basic1.c basic2.c basic3.c; do          clang -g -c $FILE -o ${FILE%.c}.macho.x86_64.o       done       clang basic1.macho.x86_64.o basic2.macho.x86_64.o basic3.macho.x86_64.o -o basic.macho.x86_64 -Wl,-dead_strip     LTO compilation:       for FILE in basic1.c basic2.c basic3.c; do          clang -g -c -flto $FILE -o ${FILE%.c}-lto.o       done       clang basic1-lto.o basic2-lto.o basic3-lto.o -o basic-lto.macho.x86_64 -Wl,-object_path_lto,$PWD/basic-lto.macho.x86_64.o -Wl,-dead_strip       rm basic1-lto.o basic2-lto.o basic3-lto.o     Archive compilation (after basic compilation):       ar -q libbasic.a basic2.macho.x86_64.o basic3.macho.x86_64.o       clang basic1.macho.x86_64.o -lbasic -o basic-archive.macho.x86_64 -Wl,-dead_strip -L. */
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
return|return
name|foo
argument_list|(
name|argc
argument_list|)
return|;
block|}
end_function

end_unit

