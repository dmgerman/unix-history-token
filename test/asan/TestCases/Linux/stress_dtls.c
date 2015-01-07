begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: asan-64-bits
end_comment

begin_comment
comment|// Stress test dynamic TLS + dlopen + threads.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that glibc 2.15 seems utterly broken on this test,
end_comment

begin_comment
comment|// it fails with ~17 DSOs dlopen-ed.
end_comment

begin_comment
comment|// glibc 2.19 seems fine.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clangxx_asan -x c -DSO_NAME=f0 %s -shared -o %t-f0.so -fPIC
end_comment

begin_comment
comment|// RUN: %clangxx_asan -x c -DSO_NAME=f1 %s -shared -o %t-f1.so -fPIC
end_comment

begin_comment
comment|// RUN: %clangxx_asan -x c -DSO_NAME=f2 %s -shared -o %t-f2.so -fPIC
end_comment

begin_comment
comment|// RUN: %clangxx_asan %s -ldl -pthread -o %t
end_comment

begin_comment
comment|// RUN: %run %t 0 3
end_comment

begin_comment
comment|// RUN: %run %t 2 3
end_comment

begin_comment
comment|// RUN: ASAN_OPTIONS=verbosity=2 %run %t 10 2 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: ASAN_OPTIONS=verbosity=2:intercept_tls_get_addr=1 %run %t 10 2 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: ASAN_OPTIONS=verbosity=2:intercept_tls_get_addr=0 %run %t 10 2 2>&1 | FileCheck %s --check-prefix=CHECK0
end_comment

begin_comment
comment|// CHECK: __tls_get_addr
end_comment

begin_comment
comment|// CHECK: Creating thread 0
end_comment

begin_comment
comment|// CHECK: __tls_get_addr
end_comment

begin_comment
comment|// CHECK: Creating thread 1
end_comment

begin_comment
comment|// CHECK: __tls_get_addr
end_comment

begin_comment
comment|// CHECK: Creating thread 2
end_comment

begin_comment
comment|// CHECK: __tls_get_addr
end_comment

begin_comment
comment|// CHECK: Creating thread 3
end_comment

begin_comment
comment|// CHECK: __tls_get_addr
end_comment

begin_comment
comment|// Make sure that TLS slots don't leak
end_comment

begin_comment
comment|// CHECK-NOT: num_live_dtls 5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK0-NOT: __tls_get_addr
end_comment

begin_comment
comment|/* cc=your-compiler  $cc stress_dtls.c -pthread -ldl for((i=0;i<100;i++)); do   $cc -fPIC -shared -DSO_NAME=f$i -o a.out-f$i.so stress_dtls.c; done ./a.out 2 4  #<<<<<< 2 threads, 4 libs ./a.out 3 50 #<<<<<< 3 threads, 50 libs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SO_NAME
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
name|void
modifier|*
modifier|*
function_decl|(
modifier|*
name|f_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|__thread
name|int
name|my_tls
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_N_FUNCTIONS
value|1000
end_define

begin_decl_stmt
name|f_t
name|Functions
index|[
name|MAX_N_FUNCTIONS
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|PrintStuff
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|uintptr_t
name|stack
decl_stmt|;
comment|// fprintf(stderr, "STACK: %p TLS: %p SELF: %p\n",&stack,&my_tls,
comment|//        (void *)pthread_self());
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_N_FUNCTIONS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|Functions
index|[
name|i
index|]
condition|)
break|break;
name|uintptr_t
name|dtls
init|=
operator|(
name|uintptr_t
operator|)
name|Functions
index|[
name|i
index|]
operator|(
operator|)
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  dtls[%03d]: %lx\n"
argument_list|,
name|i
argument_list|,
name|dtls
argument_list|)
expr_stmt|;
operator|*
operator|(
name|long
operator|*
operator|)
name|dtls
operator|=
literal|42
expr_stmt|;
comment|// check that this is writable.
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|num_threads
init|=
literal|1
decl_stmt|;
name|int
name|num_libs
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|argc
operator|>=
literal|2
condition|)
name|num_threads
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>=
literal|3
condition|)
name|num_libs
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|num_libs
operator|<=
name|MAX_N_FUNCTIONS
argument_list|)
expr_stmt|;
name|int
name|lib
decl_stmt|;
for|for
control|(
name|lib
operator|=
literal|0
init|;
name|lib
operator|<
name|num_libs
condition|;
name|lib
operator|++
control|)
block|{
name|char
name|buf
index|[
literal|4096
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%s-f%d.so"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|lib
argument_list|)
expr_stmt|;
name|void
modifier|*
name|handle
init|=
name|dlopen
argument_list|(
name|buf
argument_list|,
name|RTLD_LAZY
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|dlerror
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"f%d"
argument_list|,
name|lib
argument_list|)
expr_stmt|;
name|Functions
index|[
name|lib
index|]
operator|=
operator|(
name|f_t
operator|)
name|dlsym
argument_list|(
name|handle
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Functions
index|[
name|lib
index|]
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|dlerror
argument_list|()
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"LIB[%03d] %s: %p\n"
argument_list|,
name|lib
argument_list|,
name|buf
argument_list|,
name|Functions
index|[
name|lib
index|]
argument_list|)
expr_stmt|;
name|PrintStuff
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_threads
condition|;
name|i
operator|++
control|)
block|{
name|pthread_t
name|t
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Creating thread %d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
literal|0
argument_list|,
name|PrintStuff
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// SO_NAME
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DTLS_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DTLS_SIZE
value|(1<< 17)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__thread
name|void
modifier|*
name|huge_thread_local_array
index|[
name|DTLS_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
modifier|*
name|SO_NAME
parameter_list|()
block|{
return|return
operator|&
name|huge_thread_local_array
index|[
literal|0
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

