begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Peter McIlroy.  *  * %sccs.include.redist.c%  *  *	@(#)fsort.h	5.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|POW
value|20
end_define

begin_comment
comment|/* exponent for buffer size */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|(1<< POW)
end_define

begin_define
define|#
directive|define
name|MAXNUM
value|(BUFSIZE/10)
end_define

begin_comment
comment|/* lowish guess at average record size */
end_comment

begin_define
define|#
directive|define
name|BUFFEND
value|(EOF-2)
end_define

begin_define
define|#
directive|define
name|MAXFCT
value|1000
end_define

begin_define
define|#
directive|define
name|MAXLLEN
value|((1<< min(POW-4, 16)) - 14)
end_define

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
modifier|*
name|keylist
decl_stmt|,
modifier|*
modifier|*
name|l2buf
decl_stmt|,
modifier|*
name|buffer
decl_stmt|,
modifier|*
name|linebuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temp files in the stack have a file descriptor, a largest bin (maxb)  * which becomes the last non-empty bin (lastb) when the actual largest  * bin is smaller than max(half the total file, BUFSIZE)  * Max_o is the offset of maxb so it can be sought after the other bins  * are sorted. */
end_comment

begin_struct
struct|struct
name|tempfile
block|{
name|FILE
modifier|*
name|fd
decl_stmt|;
name|u_char
name|maxb
decl_stmt|;
name|u_char
name|lastb
decl_stmt|;
name|long
name|max_o
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tempfile
name|fstack
index|[
name|MAXFCT
index|]
decl_stmt|;
end_decl_stmt

end_unit

