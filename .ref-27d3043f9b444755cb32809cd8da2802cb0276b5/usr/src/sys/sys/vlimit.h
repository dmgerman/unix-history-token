begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vlimit.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * Limits for u.u_limit[i], per process, inherited.  */
end_comment

begin_define
define|#
directive|define
name|LIM_NORAISE
value|0
end_define

begin_comment
comment|/* if<> 0, can't raise limits */
end_comment

begin_define
define|#
directive|define
name|LIM_CPU
value|1
end_define

begin_comment
comment|/* max secs cpu time */
end_comment

begin_define
define|#
directive|define
name|LIM_FSIZE
value|2
end_define

begin_comment
comment|/* max size of file created */
end_comment

begin_define
define|#
directive|define
name|LIM_DATA
value|3
end_define

begin_comment
comment|/* max growth of data space */
end_comment

begin_define
define|#
directive|define
name|LIM_STACK
value|4
end_define

begin_comment
comment|/* max growth of stack */
end_comment

begin_define
define|#
directive|define
name|LIM_CORE
value|5
end_define

begin_comment
comment|/* max size of ``core'' file */
end_comment

begin_define
define|#
directive|define
name|NLIMITS
value|5
end_define

begin_define
define|#
directive|define
name|INFINITY
value|0x7fffffff
end_define

end_unit

