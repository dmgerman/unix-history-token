begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps_alloc.c - allocate a presentation stream */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/psap/RCS/ps_alloc.c,v 7.1 91/02/22 09:36:31 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/psap/RCS/ps_alloc.c,v 7.1 91/02/22 09:36:31 mrose Interim $  *  *  * $Log:	ps_alloc.c,v $  * Revision 7.1  91/02/22  09:36:31  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:13:19  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_comment
comment|/* A Presentatation Stream (or PStream) is the second generation of    "generic" I/O stream-based handling.  (For the first attempt,    take a look at the prototype implementation of the TTI Trusted Mail    Agent.)  The idea is to present a common, simple I/O paradigm (i.e.,    the UNIX v7 philosophy) to protocol-translation entities regardless of    the underlying medium (files, pipes, sockets, or strings).     New streams are created by a call to ps_alloc().  It allocates memory    and calls an open routine.  This routine fills in the dispatch vectors    for read/write and (optionally) close.  It can also fill in any other    part of the stream's structure it likes.     Once created, I/O is done using the macros ps_read/ps_write.  These    return either NOTOK or OK; depending on how things went. The read/write    routines are invoked as:  	int	iofunc (ps, data, n, in_line) 	PS	ps; 	PElementData data; 	PElementLen  n; 	int	in_line;     They should read/write upto len bytes, starting at data, and return the    number of bytes processed, or NOTOK on error.  The routine ps_io() will    make successive calls to fill/flush the data.  If the read/write routine    returns NOTOK, it should set ps_errno as well.     Streams are removed by a call to ps_free ().  It calls the close    routine, if any, which should de-commission any parts of the stream's    structure that are in use.  ps_free() will then free the allocated    memory.  */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|PS
name|ps_alloc
parameter_list|(
name|io
parameter_list|)
specifier|register
name|IFP
name|io
decl_stmt|;
block|{
specifier|register
name|PS
name|ps
decl_stmt|;
if|if
condition|(
operator|(
name|ps
operator|=
operator|(
name|PS
operator|)
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
expr|*
name|ps
argument_list|)
operator|)
operator|==
name|NULLPS
condition|)
return|return
name|NULLPS
return|;
if|if
condition|(
call|(
modifier|*
name|io
call|)
argument_list|(
name|ps
argument_list|)
operator|==
name|NOTOK
condition|)
block|{
name|ps_free
argument_list|(
name|ps
argument_list|)
expr_stmt|;
return|return
name|NULLPS
return|;
block|}
return|return
name|ps
return|;
block|}
end_function

end_unit

