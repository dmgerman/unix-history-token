begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: util.h,v $$Revision: 4.0.1.2 $$Date: 91/11/05 19:18:40 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log:	util.h,v $  * Revision 4.0.1.2  91/11/05  19:18:40  lwall  * patch11: safe malloc code now integrated into Perl's malloc when possible  *   * Revision 4.0.1.1  91/06/07  12:11:00  lwall  * patch4: new copyright notice  *   * Revision 4.0  91/03/20  01:56:48  lwall  * 4.0 baseline.  *   */
end_comment

begin_decl_stmt
name|EXT
name|int
modifier|*
name|screamfirst
name|INIT
argument_list|(
name|Null
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
modifier|*
name|screamnext
name|INIT
argument_list|(
name|Null
argument_list|(
name|int
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|safemalloc
end_ifndef

begin_function_decl
name|char
modifier|*
name|safemalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|saferealloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|cpytill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|instr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fbminstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|screaminstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbmcompile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* void	setenv(); */
end_comment

begin_function_decl
name|int
name|envix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|growstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ninstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rninstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|nsavestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|mypopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mypclose
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_MEMCPY
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BCOPY
end_ifndef

begin_function_decl
name|char
modifier|*
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BZERO
end_ifndef

begin_function_decl
name|char
modifier|*
name|bzero
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|unsigned
name|long
name|scanoct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|scanhex
parameter_list|()
function_decl|;
end_function_decl

end_unit

