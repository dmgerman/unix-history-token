begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: artio.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
end_comment

begin_decl_stmt
name|EXT
name|ART_POS
name|artpos
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* byte position in article file */
end_comment

begin_decl_stmt
name|EXT
name|ART_LINE
name|artline
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line number in article file */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|artfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* current article file pointer */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|openart
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the article number we have open */
end_comment

begin_decl_stmt
name|void
name|artio_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|artopen
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open an article unless already opened */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LINKART
end_ifdef

begin_function_decl
name|EXT
name|char
modifier|*
name|linkartname
name|INIT
parameter_list|(
name|nullstr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* real name of article for Eunice */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

