begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSTR
end_undef

begin_comment
comment|/* Whether malloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_MALLOC
end_undef

begin_comment
comment|/* Whether realloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_REALLOC
end_undef

begin_comment
comment|/* Whether free must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FREE
end_undef

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_GETENV
end_undef

begin_expr_stmt
unit|@
name|TOP
expr|@
end_expr_stmt

begin_comment
comment|/* Do we need to use the b modifier when opening binary files?  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_BINARY_FOPEN
end_undef

begin_comment
comment|/* Name of host specific header file to include in trad-core.c.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAD_HEADER
end_undef

begin_comment
comment|/* Define only if<sys/procfs.h> is available *and* it defines prstatus_t.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SYS_PROCFS_H
end_undef

begin_comment
comment|/* Do we really want to use mmap if it's available?  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MMAP
end_undef

end_unit

