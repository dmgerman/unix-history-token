begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file saframe.c  *  \brief The file implements the functions to read frame content  */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<dev/pms/config.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/saglobal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|siTraceFileID
end_ifdef

begin_undef
undef|#
directive|undef
name|siTraceFileID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|siTraceFileID
value|'D'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*! \brief Read 32 bits from a frame  *  *  Read 32 bits from a frame  *  *  \param agRoot       Handles for this instance of SAS/SATA LLL  *  \param agFrame      The frame handler  *  \param frameOffset  Offset in bytes from the beginning of valid frame bytes or IU                         to the 32-bit value to read  *  *  \return The read value  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_function
name|GLOBAL
name|bit32
name|saFrameReadBit32
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaFrameHandle_t
name|agFrame
parameter_list|,
name|bit32
name|frameOffset
parameter_list|)
block|{
name|bit8
modifier|*
name|payloadAddr
decl_stmt|;
name|bit32
name|value
init|=
literal|0
decl_stmt|;
name|smTraceFuncEnter
argument_list|(
name|hpDBG_VERY_LOUD
argument_list|,
literal|"zr"
argument_list|)
expr_stmt|;
if|if
condition|(
name|agNULL
operator|!=
name|agFrame
condition|)
block|{
comment|/* Find the address of the payload */
name|payloadAddr
operator|=
operator|(
name|bit8
operator|*
operator|)
operator|(
name|agFrame
operator|)
operator|+
name|frameOffset
expr_stmt|;
comment|/* read one DW Data */
name|value
operator|=
operator|*
operator|(
name|bit32
operator|*
operator|)
name|payloadAddr
expr_stmt|;
block|}
comment|/* (5) return value */
name|smTraceFuncExit
argument_list|(
name|hpDBG_VERY_LOUD
argument_list|,
literal|'a'
argument_list|,
literal|"zr"
argument_list|)
expr_stmt|;
return|return
name|value
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*! \brief Read a block from a frame  *  *  Read a block from a frame  *  *  \param agRoot         Handles for this instance of SAS/SATA LLL  *  \param agFrame        The frame handler  *  \param frameOffset    The offset of the frame to start read  *  \param frameBuffer    The pointer to the destination of data read from the frame  *  \param frameBufLen    Number of bytes to read from the frame  *  *  \return -void-  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_function
name|GLOBAL
name|void
name|saFrameReadBlock
parameter_list|(
name|agsaRoot_t
modifier|*
name|agRoot
parameter_list|,
name|agsaFrameHandle_t
name|agFrame
parameter_list|,
name|bit32
name|frameOffset
parameter_list|,
name|void
modifier|*
name|frameBuffer
parameter_list|,
name|bit32
name|frameBufLen
parameter_list|)
block|{
name|bit8
modifier|*
name|payloadAddr
decl_stmt|;
name|bit32
name|i
decl_stmt|;
name|smTraceFuncEnter
argument_list|(
name|hpDBG_VERY_LOUD
argument_list|,
literal|"zi"
argument_list|)
expr_stmt|;
comment|/* Sanity check */
name|SA_ASSERT
argument_list|(
name|frameBufLen
operator|<
literal|4096
argument_list|,
literal|"saFrameReadBlock read more than 4k"
argument_list|)
expr_stmt|;
if|if
condition|(
name|agNULL
operator|!=
name|agFrame
condition|)
block|{
comment|/* Find the address of the payload */
name|payloadAddr
operator|=
operator|(
name|bit8
operator|*
operator|)
operator|(
name|agFrame
operator|)
operator|+
name|frameOffset
expr_stmt|;
comment|/* Copy the frame data to the destination frame buffer */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|frameBufLen
condition|;
name|i
operator|++
control|)
block|{
operator|*
operator|(
name|bit8
operator|*
operator|)
operator|(
operator|(
name|bit8
operator|*
operator|)
name|frameBuffer
operator|+
name|i
operator|)
operator|=
operator|*
operator|(
name|bit8
operator|*
operator|)
operator|(
name|payloadAddr
operator|+
name|i
operator|)
expr_stmt|;
block|}
block|}
name|smTraceFuncExit
argument_list|(
name|hpDBG_VERY_LOUD
argument_list|,
literal|'a'
argument_list|,
literal|"zi"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

