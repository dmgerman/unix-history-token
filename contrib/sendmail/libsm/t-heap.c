begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_IDSTR
argument_list|(
argument|id
argument_list|,
literal|"@(#)$Id: t-heap.c,v 1.10 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<sm/debug.h>
end_include

begin_include
include|#
directive|include
file|<sm/heap.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|<sm/test.h>
end_include

begin_include
include|#
directive|include
file|<sm/xtrap.h>
end_include

begin_if
if|#
directive|if
name|SM_HEAP_CHECK
end_if

begin_decl_stmt
specifier|extern
name|SM_DEBUG_T
name|SmHeapCheck
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HEAP_CHECK
value|sm_debug_active(&SmHeapCheck, 1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_define
define|#
directive|define
name|HEAP_CHECK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|void
modifier|*
name|p
decl_stmt|;
name|sm_test_begin
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"test heap handling"
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|sm_debug_addsettings_x
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|p
operator|=
name|sm_malloc
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
name|p
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|p
operator|=
name|sm_realloc_x
argument_list|(
name|p
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
name|p
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|p
operator|=
name|sm_realloc
argument_list|(
name|p
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|SM_TEST
argument_list|(
name|p
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|HEAP_CHECK
condition|)
block|{
name|sm_dprintf
argument_list|(
literal|"heap with 1 30-byte block allocated:\n"
argument_list|)
expr_stmt|;
name|sm_heap_report
argument_list|(
name|smioout
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|HEAP_CHECK
condition|)
block|{
name|sm_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|sm_dprintf
argument_list|(
literal|"heap with 0 blocks allocated:\n"
argument_list|)
expr_stmt|;
name|sm_heap_report
argument_list|(
name|smioout
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|sm_dprintf
argument_list|(
literal|"xtrap count = %d\n"
argument_list|,
name|SmXtrapCount
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|DEBUG
comment|/* this will cause a core dump */
name|sm_dprintf
argument_list|(
literal|"about to free %p for the second time\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|sm_free
argument_list|(
name|p
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
return|return
name|sm_test_end
argument_list|()
return|;
block|}
end_function

end_unit

