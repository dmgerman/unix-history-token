begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Format of X.25 accounting record written  * to X25ACCTF whenever a circuit is closed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|waterloo
end_ifdef

begin_define
define|#
directive|define
name|X25ACCTF
value|"/usr/adm/logs/x25acct"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|X25ACCTF
value|"/usr/adm/x25acct"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|x25acct
block|{
name|time_t
name|x25acct_stime
decl_stmt|;
comment|/* start time */
ifdef|#
directive|ifdef
name|waterloo
name|u_long
name|x25acct_etime
decl_stmt|;
comment|/* elapsed time (seconds) */
else|#
directive|else
name|u_short
name|x25acct_etime
decl_stmt|;
comment|/* elapsed time (seconds) */
endif|#
directive|endif
name|short
name|x25acct_uid
decl_stmt|;
comment|/* user id */
name|short
name|x25acct_net
decl_stmt|;
comment|/* network id */
name|u_short
name|x25acct_psize
range|:
literal|4
decl_stmt|,
comment|/* packet size */
name|x25acct_addrlen
range|:
literal|4
decl_stmt|,
comment|/* x25acct_addr length */
name|x25acct_revcharge
range|:
literal|1
decl_stmt|,
comment|/* reverse charging */
name|x25acct_callin
range|:
literal|1
decl_stmt|,
comment|/* incoming call */
name|x25acct_unused
range|:
literal|6
decl_stmt|;
name|char
name|x25acct_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* remote DTE address (in bcd) */
name|char
name|x25acct_udata
index|[
literal|4
index|]
decl_stmt|;
comment|/* protocol id */
name|long
name|x25acct_txcnt
decl_stmt|;
comment|/* packets transmitted */
name|long
name|x25acct_rxcnt
decl_stmt|;
comment|/* packets received */
block|}
struct|;
end_struct

end_unit

