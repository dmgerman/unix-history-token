begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file controls the interface between the parser core and the auxiliary functions in entgen.c, sgmlio.c, and sgmlmsg.c */
end_comment

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|"entity.h"
end_include

begin_include
include|#
directive|include
file|"sgmldecl.h"
end_include

begin_comment
comment|/* Error types (ERRTYPE) for calls to error-handling services    performed for SGML by the text processor (SGMLIO).    NOTE: Strings in these blocks have no lengths, but cannot exceed    NAMELEN (plus 1 more byte for the zero terminator). */
end_comment

begin_define
define|#
directive|define
name|FILERR
value|0
end_define

begin_comment
comment|/* Error: file access. */
end_comment

begin_define
define|#
directive|define
name|DOCERR
value|1
end_define

begin_comment
comment|/* Error: in document markup. */
end_comment

begin_define
define|#
directive|define
name|MDERR
value|2
end_define

begin_comment
comment|/* Error: in markup declaration with subdcl. */
end_comment

begin_define
define|#
directive|define
name|MDERR2
value|3
end_define

begin_comment
comment|/* Error: in markup declaration with no subdcl. */
end_comment

begin_define
define|#
directive|define
name|EXITERR
value|4
end_define

begin_comment
comment|/* Error: terminal error in document markup. */
end_comment

begin_comment
comment|/* Quantities affecting error messages and their arguments. */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|2
end_define

begin_comment
comment|/* Maximum number of arguments in a msg. */
end_comment

begin_comment
comment|/* NOTE: Error handler must return, or next call to SGML must be RSET or END,          except for EXITERR errors which must not return. */
end_comment

begin_struct
struct|struct
name|error
block|{
comment|/* IPB for error messages. */
name|UNS
name|errtype
decl_stmt|;
comment|/* Type of error: DOC, MD, MD2, FIL. */
name|UNS
name|errnum
decl_stmt|;
comment|/* Error number. */
name|UNS
name|errsp
decl_stmt|;
comment|/* Special parameter index in message file. */
name|int
name|sverrno
decl_stmt|;
comment|/* Saved value of errno. */
name|int
name|parmno
decl_stmt|;
comment|/* MDERROR: declaration parameter number. */
name|UNCH
modifier|*
name|subdcl
decl_stmt|;
comment|/* MDERROR: subject of declaration. */
name|UNIV
name|eparm
index|[
name|MAXARGS
index|]
decl_stmt|;
comment|/* Ptrs to arguments (no length, but EOS). */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|location
block|{
name|int
name|filesw
decl_stmt|;
name|unsigned
name|long
name|rcnt
decl_stmt|;
name|int
name|ccnt
decl_stmt|;
name|UNCH
name|curchar
decl_stmt|;
name|UNCH
name|nextchar
decl_stmt|;
name|UNCH
modifier|*
name|ename
decl_stmt|;
name|UNIV
name|fcb
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ioopen
name|P
argument_list|(
operator|(
name|UNIV
operator|,
name|UNIV
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|ioclose
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ioread
name|P
argument_list|(
operator|(
name|UNIV
operator|,
name|UNCH
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|iopend
name|P
argument_list|(
operator|(
name|UNIV
operator|,
name|int
operator|,
name|UNCH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iocont
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|ioinit
name|P
argument_list|(
operator|(
expr|struct
name|switches
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ioflid
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNIV
name|entgen
name|P
argument_list|(
operator|(
expr|struct
name|fpi
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|entginit
name|P
argument_list|(
operator|(
expr|struct
name|switches
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|msgprint
name|P
argument_list|(
operator|(
expr|struct
name|error
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|msginit
name|P
argument_list|(
operator|(
expr|struct
name|switches
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNIV
name|msgsave
name|P
argument_list|(
operator|(
expr|struct
name|error
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|msgsprint
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|msgsfree
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgcnterr
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inprolog
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNCH
modifier|*
name|getgi
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getlocation
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|location
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNIV
name|rmalloc
name|P
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UNIV
name|rrealloc
name|P
argument_list|(
operator|(
name|UNIV
operator|,
name|UNS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|frem
name|P
argument_list|(
operator|(
name|UNIV
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|exiterr
name|P
argument_list|(
operator|(
name|unsigned
name|int
operator|,
expr|struct
name|parse
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getsubst
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

