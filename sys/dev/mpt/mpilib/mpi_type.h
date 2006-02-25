begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   *   *           Name:  mpi_type.h  *          Title:  MPI Basic type definitions  *  Creation Date:  June 6, 2000  *  *    mpi_type.h Version:  01.05.02  *  *  Version History  *  ---------------  *  *  Date      Version   Description  *  --------  --------  ------------------------------------------------------  *  05-08-00  00.10.01  Original release for 0.10 spec dated 4/26/2000.  *  06-06-00  01.00.01  Update version number for 1.0 release.  *  11-02-00  01.01.01  Original release for post 1.0 work  *  02-20-01  01.01.02  Added define and ifdef for MPI_POINTER.  *  08-08-01  01.02.01  Original release for v1.2 work.  *  05-11-04  01.03.01  Original release for MPI v1.3.  *  08-19-04  01.05.01  Original release for MPI v1.5.  *  08-30-05  01.05.02  Added PowerPC option to #ifdef's.  *  --------------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|MPI_TYPE_H
end_define

begin_comment
comment|/*******************************************************************************  * Define MPI_POINTER if it hasn't already been defined. By default MPI_POINTER  * is defined to be a near pointer. MPI_POINTER can be defined as a far pointer  * by defining MPI_POINTER as "far *" before this header file is included.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPI_POINTER
end_ifndef

begin_define
define|#
directive|define
name|MPI_POINTER
value|*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************************************************************** * *               B a s i c    T y p e s * *****************************************************************************/
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
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  Pointers                                                                */
end_comment

begin_comment
comment|/****************************************************************************/
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

end_unit

