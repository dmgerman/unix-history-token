begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|KEX_DEFAULT_KEX
value|"diffie-hellman-group1-sha1"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_PK_ALG
value|"ssh-dss"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_ENCRYPT
value|"3des-cbc,blowfish-cbc,arcfour,cast128-cbc"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_MAC
value|"hmac-sha1,hmac-md5,hmac-ripemd160@openssh.com"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_COMP
value|"zlib,none"
end_define

begin_define
define|#
directive|define
name|KEX_DEFAULT_LANG
value|""
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|myproposal
index|[
name|PROPOSAL_MAX
index|]
init|=
block|{
name|KEX_DEFAULT_KEX
block|,
name|KEX_DEFAULT_PK_ALG
block|,
name|KEX_DEFAULT_ENCRYPT
block|,
name|KEX_DEFAULT_ENCRYPT
block|,
name|KEX_DEFAULT_MAC
block|,
name|KEX_DEFAULT_MAC
block|,
name|KEX_DEFAULT_COMP
block|,
name|KEX_DEFAULT_COMP
block|,
name|KEX_DEFAULT_LANG
block|,
name|KEX_DEFAULT_LANG
block|}
decl_stmt|;
end_decl_stmt

end_unit

