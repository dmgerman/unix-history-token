begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: krb_err_txt.c,v 4.7 88/12/01 14:10:14 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This file contains an array of error text strings.  * The associated error codes (which are defined in "krb.h")  * follow the string in the comments at the end of each line.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|krb_err_txt
index|[
literal|256
index|]
init|=
block|{
literal|"OK"
block|,
comment|/* 000 */
literal|"Principal expired (kerberos)"
block|,
comment|/* 001 */
literal|"Service expired (kerberos)"
block|,
comment|/* 002 */
literal|"Authentication expired (kerberos)"
block|,
comment|/* 003 */
literal|"Unknown protocol version number (kerberos)"
block|,
comment|/* 004 */
literal|"Principal: Incorrect master key version (kerberos)"
block|,
comment|/* 005 */
literal|"Service: Incorrect master key version (kerberos)"
block|,
comment|/* 006 */
literal|"Bad byte order (kerberos)"
block|,
comment|/* 007 */
literal|"Principal unknown (kerberos)"
block|,
comment|/* 008 */
literal|"Principal not unique (kerberos)"
block|,
comment|/* 009 */
literal|"Principal has null key (kerberos)"
block|,
comment|/* 010 */
literal|"Reserved error message 11 (kerberos)"
block|,
comment|/* 011 */
literal|"Reserved error message 12 (kerberos)"
block|,
comment|/* 012 */
literal|"Reserved error message 13 (kerberos)"
block|,
comment|/* 013 */
literal|"Reserved error message 14 (kerberos)"
block|,
comment|/* 014 */
literal|"Reserved error message 15 (kerberos)"
block|,
comment|/* 015 */
literal|"Reserved error message 16 (kerberos)"
block|,
comment|/* 016 */
literal|"Reserved error message 17 (kerberos)"
block|,
comment|/* 017 */
literal|"Reserved error message 18 (kerberos)"
block|,
comment|/* 018 */
literal|"Reserved error message 19 (kerberos)"
block|,
comment|/* 019 */
literal|"Permission Denied (kerberos)"
block|,
comment|/* 020 */
literal|"Can't read ticket file (krb_get_cred)"
block|,
comment|/* 021 */
literal|"Can't find ticket (krb_get_cred)"
block|,
comment|/* 022 */
literal|"Reserved error message 23 (krb_get_cred)"
block|,
comment|/* 023 */
literal|"Reserved error message 24 (krb_get_cred)"
block|,
comment|/* 024 */
literal|"Reserved error message 25 (krb_get_cred)"
block|,
comment|/* 025 */
literal|"Ticket granting ticket expired (krb_mk_req)"
block|,
comment|/* 026 */
literal|"Reserved error message 27 (krb_mk_req)"
block|,
comment|/* 027 */
literal|"Reserved error message 28 (krb_mk_req)"
block|,
comment|/* 028 */
literal|"Reserved error message 29 (krb_mk_req)"
block|,
comment|/* 029 */
literal|"Reserved error message 30 (krb_mk_req)"
block|,
comment|/* 030 */
literal|"Can't decode authenticator (krb_rd_req)"
block|,
comment|/* 031 */
literal|"Ticket expired (krb_rd_req)"
block|,
comment|/* 032 */
literal|"Ticket issue date too far in the future (krb_rd_req)"
block|,
comment|/* 033 */
literal|"Repeat request (krb_rd_req)"
block|,
comment|/* 034 */
literal|"Ticket for wrong server (krb_rd_req)"
block|,
comment|/* 035 */
literal|"Request inconsistent (krb_rd_req)"
block|,
comment|/* 036 */
literal|"Time is out of bounds (krb_rd_req)"
block|,
comment|/* 037 */
literal|"Incorrect network address (krb_rd_req)"
block|,
comment|/* 038 */
literal|"Protocol version mismatch (krb_rd_req)"
block|,
comment|/* 039 */
literal|"Illegal message type (krb_rd_req)"
block|,
comment|/* 040 */
literal|"Message integrity error (krb_rd_req)"
block|,
comment|/* 041 */
literal|"Message duplicate or out of order (krb_rd_req)"
block|,
comment|/* 042 */
literal|"Unauthorized request (krb_rd_req)"
block|,
comment|/* 043 */
literal|"Reserved error message 44 (krb_rd_req)"
block|,
comment|/* 044 */
literal|"Reserved error message 45 (krb_rd_req)"
block|,
comment|/* 045 */
literal|"Reserved error message 46 (krb_rd_req)"
block|,
comment|/* 046 */
literal|"Reserved error message 47 (krb_rd_req)"
block|,
comment|/* 047 */
literal|"Reserved error message 48 (krb_rd_req)"
block|,
comment|/* 048 */
literal|"Reserved error message 49 (krb_rd_req)"
block|,
comment|/* 049 */
literal|"Reserved error message 50 (krb_rd_req)"
block|,
comment|/* 050 */
literal|"Current password is NULL (get_pw_tkt)"
block|,
comment|/* 051 */
literal|"Current password incorrect (get_pw_tkt)"
block|,
comment|/* 052 */
literal|"Protocol error (gt_pw_tkt)"
block|,
comment|/* 053 */
literal|"Error returned by KDC (gt_pw_tkt)"
block|,
comment|/* 054 */
literal|"Null ticket returned by KDC (gt_pw_tkt)"
block|,
comment|/* 055 */
literal|"Retry count exceeded (send_to_kdc)"
block|,
comment|/* 056 */
literal|"Can't send request (send_to_kdc)"
block|,
comment|/* 057 */
literal|"Reserved error message 58 (send_to_kdc)"
block|,
comment|/* 058 */
literal|"Reserved error message 59 (send_to_kdc)"
block|,
comment|/* 059 */
literal|"Reserved error message 60 (send_to_kdc)"
block|,
comment|/* 060 */
literal|"Warning: Not ALL tickets returned"
block|,
comment|/* 061 */
literal|"Password incorrect"
block|,
comment|/* 062 */
literal|"Protocol error (get_intkt)"
block|,
comment|/* 063 */
literal|"Reserved error message 64 (get_in_tkt)"
block|,
comment|/* 064 */
literal|"Reserved error message 65 (get_in_tkt)"
block|,
comment|/* 065 */
literal|"Reserved error message 66 (get_in_tkt)"
block|,
comment|/* 066 */
literal|"Reserved error message 67 (get_in_tkt)"
block|,
comment|/* 067 */
literal|"Reserved error message 68 (get_in_tkt)"
block|,
comment|/* 068 */
literal|"Reserved error message 69 (get_in_tkt)"
block|,
comment|/* 069 */
literal|"Generic error (get_intkt)"
block|,
comment|/* 070 */
literal|"Don't have ticket granting ticket (get_ad_tkt)"
block|,
comment|/* 071 */
literal|"Reserved error message 72 (get_ad_tkt)"
block|,
comment|/* 072 */
literal|"Reserved error message 73 (get_ad_tkt)"
block|,
comment|/* 073 */
literal|"Reserved error message 74 (get_ad_tkt)"
block|,
comment|/* 074 */
literal|"Reserved error message 75 (get_ad_tkt)"
block|,
comment|/* 075 */
literal|"No ticket file (tf_util)"
block|,
comment|/* 076 */
literal|"Can't access ticket file (tf_util)"
block|,
comment|/* 077 */
literal|"Can't lock ticket file; try later (tf_util)"
block|,
comment|/* 078 */
literal|"Bad ticket file format (tf_util)"
block|,
comment|/* 079 */
literal|"Read ticket file before tf_init (tf_util)"
block|,
comment|/* 080 */
literal|"Bad Kerberos name format (kname_parse)"
block|,
comment|/* 081 */
literal|"Can't open socket"
block|,
comment|/* 082 */
literal|"Can't retrieve local interface list"
block|,
comment|/* 083 */
literal|"No valid local interface found"
block|,
comment|/* 084 */
literal|"Can't bind local address"
block|,
comment|/* 085 */
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"(reserved)"
block|,
literal|"Generic kerberos error (kfailure)"
block|,
comment|/* 255 */
block|}
decl_stmt|;
end_decl_stmt

end_unit

