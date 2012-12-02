begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__USAGE_H
end_ifndef

begin_define
define|#
directive|define
name|__USAGE_H
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_help_usage
index|[]
init|=
literal|"Usage: %s help topic=<cmd>\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tcmd\t- [help|read|write|erase|readoob|writeoob|info]\n"
literal|"\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_read_usage
index|[]
init|=
literal|"Usage: %s read dev=<gnand_device> (block|page|pos)=n [count=n]\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
literal|"\tblock\t- starting block or\n"
literal|"\tpage\t- starting page or\n"
literal|"\tpos\t- starting position (in bytes, must be page-aligned)\n"
literal|"\tout\t- output file (hexdump to stdout if not supplied)\n"
literal|"\n"
literal|"Note that you can only specify only one of: 'block', 'page', 'pos'\n"
literal|"parameters at once. 'count' parameter is meaningful in terms of used\n"
literal|"unit (page, block or byte).\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_write_usage
index|[]
init|=
literal|"Usage: %s write dev=<gnand_device> in=<file> (block|page|pos)=n [count=n]\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
literal|"\tin\t- path to input file which be writed to gnand\n"
literal|"\tblock\t- starting block or\n"
literal|"\tpage\t- starting page or\n"
literal|"\tpos\t- starting position (in bytes, must be page-aligned)\n"
literal|"\tcount\t- byte/page/block count\n"
literal|"\n"
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_erase_usage
index|[]
init|=
literal|"Usage: %s erase dev=<gnand_device> (block|page|pos)=n [count=n]\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
literal|"\tblock\t- starting block or\n"
literal|"\tpage\t- starting page or\n"
literal|"\tpos\t- starting position (in bytes, muse be block-aligned)\n"
literal|"\tcount\t- byte/page/block count\n"
literal|"\n"
literal|"NOTE: position and count for erase operation MUST be block-aligned\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_read_oob_usage
index|[]
init|=
literal|"Usage: %s readoob dev=<gnand_device> page=n [out=file] [count=n]\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
literal|"\tpage\t- page (page) number\n"
literal|"\tout\t- outut file (hexdump to stdout if not supplied)\n"
literal|"\tcount\t- page count (default is 1)\n"
literal|"\n"
literal|"If you supply count parameter with value other than 1, data will be\n"
literal|"read from subsequent page's OOB areas\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_write_oob_usage
index|[]
init|=
literal|"Usage: %s writeoob dev=<gnand_device> in=<file> page=n [count=n]\n"
literal|"\n"
literal|"\tdev\t- path to gnand device node\n"
literal|"\tin\t- path to file containing data which will be written\n"
literal|"\tpage\t- page (page) number\n"
literal|"\n"
literal|"If you supply count parameter with value other than 1, data will be\n"
literal|"written to subsequent page's OOB areas\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_info_usage
index|[]
init|=
literal|"Usage: %s info dev=<gnand_device>\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|nand_stats_usage
index|[]
init|=
literal|"Usage: %s stats dev=<gnand_device> (page|block)=<n>\n"
literal|"\n"
literal|"Arguments:\n"
literal|"\tdev\t- path to gnand device node\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __USAGE_H */
end_comment

end_unit

