begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** Various exit codes. ** **	They come from<sysexits.h> **	Defined here to avoid including /usr/ucbinclude on solaris 2.x ** **	@(#)exit.h              e07@nikhef.nl (Eric Wassenaar) 930903 */
end_comment

begin_define
define|#
directive|define
name|EX_OK
value|0
end_define

begin_comment
comment|/* successful termination */
end_comment

begin_define
define|#
directive|define
name|EX_USAGE
value|64
end_define

begin_comment
comment|/* command line usage error */
end_comment

begin_define
define|#
directive|define
name|EX_DATAERR
value|65
end_define

begin_comment
comment|/* data format error */
end_comment

begin_define
define|#
directive|define
name|EX_NOINPUT
value|66
end_define

begin_comment
comment|/* cannot open input */
end_comment

begin_define
define|#
directive|define
name|EX_NOUSER
value|67
end_define

begin_comment
comment|/* addressee unknown */
end_comment

begin_define
define|#
directive|define
name|EX_NOHOST
value|68
end_define

begin_comment
comment|/* host name unknown */
end_comment

begin_define
define|#
directive|define
name|EX_UNAVAILABLE
value|69
end_define

begin_comment
comment|/* service unavailable */
end_comment

begin_define
define|#
directive|define
name|EX_SOFTWARE
value|70
end_define

begin_comment
comment|/* internal software error */
end_comment

begin_define
define|#
directive|define
name|EX_OSERR
value|71
end_define

begin_comment
comment|/* system error (e.g., can't fork) */
end_comment

begin_define
define|#
directive|define
name|EX_OSFILE
value|72
end_define

begin_comment
comment|/* critical OS file missing */
end_comment

begin_define
define|#
directive|define
name|EX_CANTCREAT
value|73
end_define

begin_comment
comment|/* can't create (user) output file */
end_comment

begin_define
define|#
directive|define
name|EX_IOERR
value|74
end_define

begin_comment
comment|/* input/output error */
end_comment

begin_define
define|#
directive|define
name|EX_TEMPFAIL
value|75
end_define

begin_comment
comment|/* temp failure; user is invited to retry */
end_comment

begin_define
define|#
directive|define
name|EX_PROTOCOL
value|76
end_define

begin_comment
comment|/* remote error in protocol */
end_comment

begin_define
define|#
directive|define
name|EX_NOPERM
value|77
end_define

begin_comment
comment|/* permission denied */
end_comment

begin_define
define|#
directive|define
name|EX_CONFIG
value|78
end_define

begin_comment
comment|/* local configuration error */
end_comment

end_unit

