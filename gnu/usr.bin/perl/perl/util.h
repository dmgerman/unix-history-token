begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: util.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:29 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: util.h,v $  * Revision 1.2  1995/05/30 05:03:29  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:40  nate  * PERL!  *  * Revision 4.0.1.4  92/06/11  21:19:36  lwall  * patch34: pidgone() wasn't declared right  *  * Revision 4.0.1.3  92/06/08  16:09:20  lwall  * patch20: bcopy() and memcpy() now tested for overlap safety  *  * Revision 4.0.1.2  91/11/05  19:18:40  lwall  * patch11: safe malloc code now integrated into Perl's malloc when possible  *  * Revision 4.0.1.1  91/06/07  12:11:00  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:56:48  lwall  * 4.0 baseline.  *  */
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

begin_function_decl
name|void
name|my_setenv
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_BCOPY
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SAFE_BCOPY
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|my_bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_BZERO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_MEMSET
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|my_bzero
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
name|HAS_MEMCMP
end_ifndef

begin_function_decl
name|int
name|my_memcmp
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|pidgone
parameter_list|()
function_decl|;
end_function_decl

end_unit

