begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_WTIO_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_WTIO_H
end_define

begin_comment
comment|/*  * Streamer tape driver for 386bsd and FreeBSD.  * Supports Archive and Wangtek compatible QIC-02/QIC-36 boards.  *  * Copyright (C) 1993 by:  *      Sergey Ryzhkov<sir@kiae.su>  *      Serge Vakulenko<vak@zebub.msk.su>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * This driver is derived from the old 386bsd Wangtek streamer tape driver,  * made by Robert Baron at CMU, based on Intel sources.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* formats for printing flags and error values */
end_comment

begin_define
define|#
directive|define
name|WTDS_BITS
value|"\20\1inuse\2read\3write\4start\5rmark\6wmark\7rew\10excep\11vol\12wo\13ro\14wany\15rany\16wp\17timer\20active"
end_define

begin_define
define|#
directive|define
name|WTER_BITS
value|"\20\1eof\2bnl\3uda\4eom\5wrp\6usl\7cni\11por\12erm\13bpe\14bom\15mbd\16ndt\17ill"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_WTIO_H */
end_comment

end_unit

