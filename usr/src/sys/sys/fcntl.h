begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	fcntl.h	4.1	83/07/03	*/
end_comment

begin_comment
comment|/*  * Flag values accessible to open(2) and fcntl(2)  *  (The first three can only be set by open)  */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_define
define|#
directive|define
name|O_NDELAY
value|04
end_define

begin_comment
comment|/* Non-blocking I/O */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|010
end_define

begin_comment
comment|/* append (writes guaranteed at the end) */
end_comment

begin_comment
comment|/* fcntl(2) requests */
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* Duplicate fildes */
end_comment

begin_define
define|#
directive|define
name|F_GETFD
value|1
end_define

begin_comment
comment|/* Get fildes flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_comment
comment|/* Set fildes flags */
end_comment

begin_define
define|#
directive|define
name|F_GETFL
value|3
end_define

begin_comment
comment|/* Get file flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|4
end_define

begin_comment
comment|/* Set file flags */
end_comment

begin_define
define|#
directive|define
name|F_GETOWN
value|5
end_define

begin_comment
comment|/* Get owner */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN
value|6
end_define

begin_comment
comment|/* Set owner */
end_comment

end_unit

