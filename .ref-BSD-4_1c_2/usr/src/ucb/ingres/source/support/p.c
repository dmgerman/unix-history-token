begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|# 1 "write.c"
end_empty

begin_empty
empty|# 1 "./SYS.h"
end_empty

begin_empty
empty|# 1 "/usr/include/syscall.h"
end_empty

begin_empty
empty|# 4 "./SYS.h"
end_empty

begin_empty
empty|# 10 "./SYS.h"
end_empty

begin_expr_stmt
operator|.
name|globl
name|cerror
empty|# 4 "write.c"
name|err
operator|:
name|jmp
name|cerror
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|.
name|globl
name|_foobar
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|.
name|align
literal|2
expr_stmt|;
end_expr_stmt

begin_label
name|_foobar
label|:
end_label

begin_expr_stmt
operator|.
name|word
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|.
name|data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
literal|1
operator|:
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|.
name|long
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|.
name|text
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|moval
literal|1b
operator|,
name|r0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|jsb
name|mcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|chmk
name|$4
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|jcs
name|err
name|ret
end_expr_stmt

end_unit

