begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  *   based on work by Slawa Olhovchenkov  *                    John Prince<johnp@knight-trosoft.com>  *                    Eric Hernes  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * A very small subset of cards.  */
end_comment

begin_enum
enum|enum
name|digi_model
block|{
name|PCXE
block|,
name|PCXEVE
block|,
name|PCXI
block|,
name|PCXEM
block|,
name|PCCX
block|,
name|PCIEPCX
block|,
name|PCIXR
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|DIGIDB_INIT
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|DIGIDB_OPEN
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|DIGIDB_CLOSE
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|DIGIDB_SET
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|DIGIDB_INT
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|DIGIDB_READ
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|DIGIDB_WRITE
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|DIGIDB_RX
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|DIGIDB_TX
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|DIGIDB_IRQ
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|DIGIDB_MODEM
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|DIGIDB_RI
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|DIGIIO_REINIT
value|_IO('e', 'A')
end_define

begin_define
define|#
directive|define
name|DIGIIO_DEBUG
value|_IOW('e', 'B', int)
end_define

begin_define
define|#
directive|define
name|DIGIIO_RING
value|_IO('e', 'C')
end_define

begin_define
define|#
directive|define
name|DIGIIO_MODEL
value|_IOR('e', 'D', enum digi_model)
end_define

begin_define
define|#
directive|define
name|DIGIIO_IDENT
value|_IOW('e', 'E', char *)
end_define

begin_define
define|#
directive|define
name|DIGIIO_SETALTPIN
value|_IOW('e', 'F', int)
end_define

begin_define
define|#
directive|define
name|DIGIIO_GETALTPIN
value|_IOR('e', 'G', int)
end_define

end_unit

