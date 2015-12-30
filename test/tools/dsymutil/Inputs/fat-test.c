begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compile with:    clang -c -g -arch x86_64h -arch x86_64 -arch i386 fat-test.c    libtool -static -o libfat-test.a fat-test.o     to generate a dylib instead:    clang -arch ...  -arch ... -arch ...  -dynamiclib fat-test.o -o fat-test.dylib     To reduce the size of the fat binary:    lipo -thin i386 -o fat-test.i386.o fat-test.o     lipo -thin x86_64 -o fat-test.x86_64.o fat-test.o     lipo -thin x86_64h -o fat-test.x86_64h.o fat-test.o     lipo -create -arch x86_64h fat-test.x86_64h.o -arch x86_64 fat-test.x86_64.o -arch i386 fat-test.i386.o -o fat-test.o -segalign i386 8 -segalign x86_64 8 -segalign x86_64h 8  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64h__
end_ifdef

begin_decl_stmt
name|int
name|x86_64h_var
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|x86_64_var
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|i386_var
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7S__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|armv7s_var
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|armv7_var
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM64_ARCH_8__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|arm64_var
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unknown architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

