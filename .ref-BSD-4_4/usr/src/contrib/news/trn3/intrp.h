begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: intrp.h,v 3.0 1992/02/01 03:09:32 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|lib
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* news library */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|rnlib
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* private news program library */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|origdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cwd when rn invoked */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|homedir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* login directory */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|dotdir
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* where . files go */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|logname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* login id of user */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|realname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* real name of user */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|phostname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* host name in a posting */
end_comment

begin_decl_stmt
name|EXT
name|int
name|perform_cnt
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEWS_ADMIN
end_ifdef

begin_function_decl
name|EXT
name|char
name|newsadmin
index|[]
name|INIT
parameter_list|(
name|NEWS_ADMIN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* news administrator */
end_comment

begin_decl_stmt
name|EXT
name|int
name|newsuid
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|intrp_init
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|filexp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dointerp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|interp
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|refscpy
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getrealname
name|_
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

