begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_OPENSSLV_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_OPENSSLV_H
end_define

begin_comment
comment|/* Numeric release version identifier:  * MMNNFFRBB: major minor fix final beta/patch  * For example:  * 0.9.3-dev	  0x00903000  * 0.9.3beta1	  0x00903001  * 0.9.3beta2-dev 0x00903002  * 0.9.3beta2     0x00903002  * 0.9.3	  0x00903100  * 0.9.3a	  0x00903101  * 0.9.4 	  0x00904100  * 1.2.3z	  0x1020311a  * (Prior to 0.9.3-dev a different scheme was used: 0.9.2b is 0x0922.)  */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_VERSION_NUMBER
value|0x00904100L
end_define

begin_define
define|#
directive|define
name|OPENSSL_VERSION_TEXT
value|"OpenSSL 0.9.4 09 Aug 1999"
end_define

begin_define
define|#
directive|define
name|OPENSSL_VERSION_PTEXT
value|" part of " OPENSSL_VERSION_TEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_OPENSSLV_H */
end_comment

end_unit

