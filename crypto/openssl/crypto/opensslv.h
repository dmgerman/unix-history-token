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
comment|/* Numeric release version identifier:  * MMNNFFPPS: major minor fix patch status  * The status nibble has one of the values 0 for development, 1 to e for betas  * 1 to 14, and f for release.  The patch level is exactly that.  * For example:  * 0.9.3-dev	  0x00903000  * 0.9.3-beta1	  0x00903001  * 0.9.3-beta2-dev 0x00903002  * 0.9.3-beta2    0x00903002 (same as ...beta2-dev)  * 0.9.3	  0x0090300f  * 0.9.3a	  0x0090301f  * 0.9.4 	  0x0090400f  * 1.2.3z	  0x102031af  *  * For continuity reasons (because 0.9.5 is already out, and is coded  * 0x00905100), between 0.9.5 and 0.9.6 the coding of the patch level  * part is slightly different, by setting the highest bit.  This means  * that 0.9.5a looks like this: 0x0090581f.  At 0.9.6, we can start  * with 0x0090600S...  *  * (Prior to 0.9.3-dev a different scheme was used: 0.9.2b is 0x0922.)  * (Prior to 0.9.5a beta1, a different scheme was used: MMNNFFRBB for  *  major minor fix final patch/beta)  */
end_comment

begin_define
define|#
directive|define
name|OPENSSL_VERSION_NUMBER
value|0x0090581fL
end_define

begin_define
define|#
directive|define
name|OPENSSL_VERSION_TEXT
value|"OpenSSL 0.9.5a 1 Apr 2000"
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

