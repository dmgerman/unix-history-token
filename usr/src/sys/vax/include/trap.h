begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	trap.h	4.6	81/03/03	*/
end_comment

begin_comment
comment|/*  * Trap type values  */
end_comment

begin_comment
comment|/* The first three constant values are known to the real world<signal.h> */
end_comment

begin_define
define|#
directive|define
name|RESADFLT
value|0
end_define

begin_comment
comment|/* reserved addressing fault */
end_comment

begin_define
define|#
directive|define
name|PRIVINFLT
value|1
end_define

begin_comment
comment|/* privileged instruction fault */
end_comment

begin_define
define|#
directive|define
name|RESOPFLT
value|2
end_define

begin_comment
comment|/* reserved operand fault */
end_comment

begin_comment
comment|/* End of known constants */
end_comment

begin_define
define|#
directive|define
name|BPTFLT
value|3
end_define

begin_comment
comment|/* bpt instruction fault */
end_comment

begin_define
define|#
directive|define
name|XFCFLT
value|4
end_define

begin_comment
comment|/* xfc instruction fault */
end_comment

begin_define
define|#
directive|define
name|SYSCALL
value|5
end_define

begin_comment
comment|/* chmk instruction (syscall trap) */
end_comment

begin_define
define|#
directive|define
name|ARITHTRAP
value|6
end_define

begin_comment
comment|/* arithmetic trap */
end_comment

begin_define
define|#
directive|define
name|ASTFLT
value|7
end_define

begin_comment
comment|/* software level 2 trap (ast deliv) */
end_comment

begin_define
define|#
directive|define
name|SEGFLT
value|8
end_define

begin_comment
comment|/* segmentation fault */
end_comment

begin_define
define|#
directive|define
name|PROTFLT
value|9
end_define

begin_comment
comment|/* protection fault */
end_comment

begin_define
define|#
directive|define
name|TRCTRAP
value|10
end_define

begin_comment
comment|/* trace trap */
end_comment

begin_define
define|#
directive|define
name|COMPATFLT
value|11
end_define

begin_comment
comment|/* compatibility mode fault */
end_comment

begin_define
define|#
directive|define
name|PAGEFLT
value|12
end_define

begin_comment
comment|/* page fault */
end_comment

begin_define
define|#
directive|define
name|TABLEFLT
value|13
end_define

begin_comment
comment|/* page table fault */
end_comment

end_unit

