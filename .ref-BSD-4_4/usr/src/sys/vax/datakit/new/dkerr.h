begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * This include file dkerr.h defines the NAK reason codes sent to the host  * from a DATAKIT VCS node                                                  * *                 @(#)dkerr.h	2.2 DKHOST 85/01/08 */
end_comment

begin_define
define|#
directive|define
name|BUSY
value|1
end_define

begin_define
define|#
directive|define
name|NOCMC
value|2
end_define

begin_define
define|#
directive|define
name|NODEST
value|3
end_define

begin_define
define|#
directive|define
name|INTERT
value|4
end_define

begin_define
define|#
directive|define
name|REORT
value|5
end_define

begin_define
define|#
directive|define
name|EXIST
value|6
end_define

begin_define
define|#
directive|define
name|NOMSG
value|6
end_define

begin_define
define|#
directive|define
name|NOACC
value|7
end_define

begin_comment
comment|/* Access denied */
end_comment

begin_define
define|#
directive|define
name|DIRASS
value|8
end_define

begin_comment
comment|/* Directory Assistance */
end_comment

begin_comment
comment|/* The next set of codes are NAK reasons sent * from the auto-dialer process */
end_comment

begin_define
define|#
directive|define
name|NEEDNUM
value|9
end_define

begin_comment
comment|/* Need a valid number */
end_comment

begin_define
define|#
directive|define
name|ADFAIL
value|10
end_define

begin_comment
comment|/* Autodialer died */
end_comment

begin_define
define|#
directive|define
name|WFAIL
value|11
end_define

begin_comment
comment|/* Autodialer failed while dialing */
end_comment

begin_define
define|#
directive|define
name|NOIDIAL
value|12
end_define

begin_comment
comment|/* No initial dialtone */
end_comment

begin_define
define|#
directive|define
name|NOSDIAL
value|13
end_define

begin_comment
comment|/* No secondary dialtone */
end_comment

begin_define
define|#
directive|define
name|LINBUSY
value|14
end_define

begin_comment
comment|/* Dialed number is busy */
end_comment

begin_define
define|#
directive|define
name|NOANS
value|15
end_define

begin_comment
comment|/* RING...RING...RING...RING... */
end_comment

begin_define
define|#
directive|define
name|NOCAR
value|16
end_define

begin_comment
comment|/* RING...Hello??? No carrier! */
end_comment

begin_define
define|#
directive|define
name|NOREAS
value|17
end_define

begin_comment
comment|/* It failed. Why?  No clues! */
end_comment

begin_comment
comment|/* The next set of codes are NAK reasons sent * from the DATAKIT host process */
end_comment

begin_define
define|#
directive|define
name|NLINE
value|130
end_define

begin_define
define|#
directive|define
name|NSRVTAB
value|133
end_define

begin_define
define|#
directive|define
name|NCHROOT
value|134
end_define

end_unit

