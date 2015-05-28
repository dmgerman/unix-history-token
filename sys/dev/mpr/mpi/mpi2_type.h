begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 LSI Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Copyright (c) 2000-2007 LSI Corporation.  *  *  *           Name:  mpi2_type.h  *          Title:  MPI basic type definitions  *  Creation Date:  August 16, 2006  *  *    mpi2_type.h Version:  02.00.00  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  04-30-07  02.00.00  Corresponds to Fusion-MPT MPI Specification Rev A.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|MPI2_TYPE_H
end_define

begin_comment
comment|/*******************************************************************************  * Define MPI2_POINTER if it hasn't already been defined. By default  * MPI2_POINTER is defined to be a near pointer. MPI2_POINTER can be defined as  * a far pointer by defining MPI2_POINTER as "far *" before this header file is  * included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI2_POINTER
end_ifndef

begin_define
define|#
directive|define
name|MPI2_POINTER
value|*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the basic types may have already been included by mpi_type.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_TYPE_H
end_ifndef

begin_comment
comment|/***************************************************************************** * *               Basic Types * *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|S8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|S16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|U16
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_typedef
typedef|typedef
name|int32_t
name|S32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|U32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm
argument_list|)
operator|||
name|defined
argument_list|(
name|ALPHA
argument_list|)
operator|||
name|defined
argument_list|(
name|__PPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc
argument_list|)
end_if

begin_typedef
typedef|typedef
name|signed
name|int
name|S32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|U32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|long
name|S32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|U32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_S64
block|{
name|U32
name|Low
decl_stmt|;
name|S32
name|High
decl_stmt|;
block|}
name|S64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_U64
block|{
name|U32
name|Low
decl_stmt|;
name|U32
name|High
decl_stmt|;
block|}
name|U64
typedef|;
end_typedef

begin_comment
comment|/***************************************************************************** * *               Pointer Types * *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|S8
modifier|*
name|PS8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U8
modifier|*
name|PU8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|S16
modifier|*
name|PS16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U16
modifier|*
name|PU16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|S32
modifier|*
name|PS32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U32
modifier|*
name|PU32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|S64
modifier|*
name|PS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U64
modifier|*
name|PU64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

