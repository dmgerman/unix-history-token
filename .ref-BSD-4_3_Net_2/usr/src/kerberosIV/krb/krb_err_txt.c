begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/krb_err_txt.c,v $  * $Author: karels $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_krb_err_txt_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/krb_err_txt.c,v 4.9 91/06/01 13:53:20 karels Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_comment
comment|/*  * This file contains an array of error text strings.  * The associated error codes (which are defined in "krb.h")  * follow the string in the comments at the end of each line.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|_kreserved
index|[]
init|=
literal|"(reserved)"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|krb_err_txt
index|[
literal|256
index|]
init|=
block|{
literal|"No Error"
block|,
comment|/* 000 */
literal|"Principal expired"
block|,
comment|/* 001 */
literal|"Service expired"
block|,
comment|/* 002 */
literal|"Authentication expired"
block|,
comment|/* 003 */
literal|"Unknown protocol version number"
block|,
comment|/* 004 */
literal|"Principal: Incorrect master key version"
block|,
comment|/* 005 */
literal|"Service: Incorrect master key version"
block|,
comment|/* 006 */
literal|"Bad byte order"
block|,
comment|/* 007 */
literal|"Principal unknown"
block|,
comment|/* 008 */
literal|"Principal not unique"
block|,
comment|/* 009 */
literal|"Principal has null key"
block|,
comment|/* 010 */
literal|"Reserved error message 11"
block|,
comment|/* 011 */
literal|"Reserved error message 12"
block|,
comment|/* 012 */
literal|"Reserved error message 13"
block|,
comment|/* 013 */
literal|"Reserved error message 14"
block|,
comment|/* 014 */
literal|"Reserved error message 15"
block|,
comment|/* 015 */
literal|"Reserved error message 16"
block|,
comment|/* 016 */
literal|"Reserved error message 17"
block|,
comment|/* 017 */
literal|"Reserved error message 18"
block|,
comment|/* 018 */
literal|"Reserved error message 19"
block|,
comment|/* 019 */
literal|"Permission Denied"
block|,
comment|/* 020 */
literal|"Can't read ticket file"
block|,
comment|/* 021 */
literal|"Can't find ticket"
block|,
comment|/* 022 */
literal|"Reserved error message 23"
block|,
comment|/* 023 */
literal|"Reserved error message 24"
block|,
comment|/* 024 */
literal|"Reserved error message 25"
block|,
comment|/* 025 */
literal|"Ticket granting ticket expired"
block|,
comment|/* 026 */
literal|"Reserved error message 27"
block|,
comment|/* 027 */
literal|"Reserved error message 28"
block|,
comment|/* 028 */
literal|"Reserved error message 29"
block|,
comment|/* 029 */
literal|"Reserved error message 30"
block|,
comment|/* 030 */
literal|"Can't decode authenticator"
block|,
comment|/* 031 */
literal|"Ticket expired"
block|,
comment|/* 032 */
literal|"Ticket issue date too far in the future"
block|,
comment|/* 033 */
literal|"Repeat request"
block|,
comment|/* 034 */
literal|"Ticket for wrong server"
block|,
comment|/* 035 */
literal|"Request inconsistent"
block|,
comment|/* 036 */
literal|"Time is out of bounds"
block|,
comment|/* 037 */
literal|"Incorrect network address"
block|,
comment|/* 038 */
literal|"Protocol version mismatch"
block|,
comment|/* 039 */
literal|"Illegal message type"
block|,
comment|/* 040 */
literal|"Message integrity error"
block|,
comment|/* 041 */
literal|"Message duplicate or out of order"
block|,
comment|/* 042 */
literal|"Unauthorized request"
block|,
comment|/* 043 */
literal|"Reserved error message 44"
block|,
comment|/* 044 */
literal|"Reserved error message 45"
block|,
comment|/* 045 */
literal|"Reserved error message 46"
block|,
comment|/* 046 */
literal|"Reserved error message 47"
block|,
comment|/* 047 */
literal|"Reserved error message 48"
block|,
comment|/* 048 */
literal|"Reserved error message 49"
block|,
comment|/* 049 */
literal|"Reserved error message 50"
block|,
comment|/* 050 */
literal|"Current password is NULL"
block|,
comment|/* 051 */
literal|"Current password incorrect"
block|,
comment|/* 052 */
literal|"Protocol error"
block|,
comment|/* 053 */
literal|"Error returned by KDC"
block|,
comment|/* 054 */
literal|"Null ticket returned by KDC"
block|,
comment|/* 055 */
literal|"Retry count exceeded"
block|,
comment|/* 056 */
literal|"Can't send request"
block|,
comment|/* 057 */
literal|"Reserved error message 58"
block|,
comment|/* 058 */
literal|"Reserved error message 59"
block|,
comment|/* 059 */
literal|"Reserved error message 60"
block|,
comment|/* 060 */
literal|"Warning: Not ALL tickets returned"
block|,
comment|/* 061 */
literal|"Password incorrect"
block|,
comment|/* 062 */
literal|"Protocol error"
block|,
comment|/* 063 */
literal|"Reserved error message 64"
block|,
comment|/* 064 */
literal|"Reserved error message 65"
block|,
comment|/* 065 */
literal|"Reserved error message 66"
block|,
comment|/* 066 */
literal|"Reserved error message 67"
block|,
comment|/* 067 */
literal|"Reserved error message 68"
block|,
comment|/* 068 */
literal|"Reserved error message 69"
block|,
comment|/* 069 */
literal|"Unknown initial-ticket error"
block|,
comment|/* 070 */
literal|"Don't have ticket granting ticket"
block|,
comment|/* 071 */
literal|"Reserved error message 72"
block|,
comment|/* 072 */
literal|"Reserved error message 73"
block|,
comment|/* 073 */
literal|"Reserved error message 74"
block|,
comment|/* 074 */
literal|"Reserved error message 75"
block|,
comment|/* 075 */
literal|"No ticket file"
block|,
comment|/* 076 */
literal|"Can't access ticket file"
block|,
comment|/* 077 */
literal|"Can't lock ticket file; try later"
block|,
comment|/* 078 */
literal|"Bad ticket file format"
block|,
comment|/* 079 */
literal|"Read ticket file before tf_init"
block|,
comment|/* 080 */
literal|"Bad Kerberos name format"
block|,
comment|/* 081 */
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
name|_kreserved
block|,
literal|"Generic kerberos error (KFAILURE)"
block|,
comment|/* 255 */
block|}
decl_stmt|;
end_decl_stmt

end_unit

