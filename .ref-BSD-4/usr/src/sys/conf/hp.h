begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hp.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * MASSBUS on which rp06/rm03/rm05 is  */
end_comment

begin_define
define|#
directive|define
name|HPMBA
value|MBA0
end_define

begin_define
define|#
directive|define
name|HPMBANUM
value|0
end_define

begin_comment
comment|/*  * Number of drives  */
end_comment

begin_define
define|#
directive|define
name|NHP
value|2
end_define

begin_comment
comment|/*  * Drive numbers assigned for iostat/vmstat  * Currently drives on hp are 0 and 1, drives on up are 2 and 3.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DK_N
end_ifndef

begin_define
define|#
directive|define
name|DK_N
value|0
end_define

begin_define
define|#
directive|define
name|DK_NMAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

