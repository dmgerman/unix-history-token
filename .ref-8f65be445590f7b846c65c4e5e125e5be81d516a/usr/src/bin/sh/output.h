begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)output.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OUTPUT_INCL
end_ifndef

begin_struct
struct|struct
name|output
block|{
name|char
modifier|*
name|nextc
decl_stmt|;
name|int
name|nleft
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|bufsize
decl_stmt|;
name|short
name|fd
decl_stmt|;
name|short
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|output
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|output
name|errout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|output
name|memout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|output
modifier|*
name|out1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|output
modifier|*
name|out2
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|outstr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1str
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out2str
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outfmt
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1fmt
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fmtstr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void doformat(struct output *, char *, va_list); */
end_comment

begin_function_decl
name|void
name|doformat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emptyoutbuf
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushout
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freestdout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xwrite
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xioctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|outstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outfmt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1fmt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fmtstr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* void doformat(); */
end_comment

begin_function_decl
name|void
name|doformat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emptyoutbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freestdout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xioctl
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|outc
parameter_list|(
name|c
parameter_list|,
name|file
parameter_list|)
value|(--(file)->nleft< 0? (emptyoutbuf(file), *(file)->nextc++ = (c)) : (*(file)->nextc++ = (c)))
end_define

begin_define
define|#
directive|define
name|out1c
parameter_list|(
name|c
parameter_list|)
value|outc(c, out1);
end_define

begin_define
define|#
directive|define
name|out2c
parameter_list|(
name|c
parameter_list|)
value|outc(c, out2);
end_define

begin_define
define|#
directive|define
name|OUTPUT_INCL
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

