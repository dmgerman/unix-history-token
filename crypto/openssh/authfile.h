begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|AUTHFILE_H
end_ifndef

begin_define
define|#
directive|define
name|AUTHFILE_H
end_define

begin_comment
comment|/*  * Saves the authentication (private) key in a file, encrypting it with  * passphrase.  * For RSA keys: The identification of the file (lowest 64 bits of n)  * will precede the key to provide identification of the key without  * needing a passphrase.  */
end_comment

begin_function_decl
name|int
name|save_private_key
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|passphrase
parameter_list|,
name|Key
modifier|*
name|private_key
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Loads the public part of the key file (public key and comment). Returns 0  * if an error occurred; zero if the public key was successfully read.  The  * comment of the key is returned in comment_return if it is non-NULL; the  * caller must free the value with xfree.  */
end_comment

begin_function_decl
name|int
name|load_public_key
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|Key
modifier|*
name|pub
parameter_list|,
name|char
modifier|*
modifier|*
name|comment_return
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Loads the private key from the file.  Returns 0 if an error is encountered  * (file does not exist or is not readable, or passphrase is bad). This  * initializes the private key.  The comment of the key is returned in  * comment_return if it is non-NULL; the caller must free the value with  * xfree.  */
end_comment

begin_function_decl
name|int
name|load_private_key
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|passphrase
parameter_list|,
name|Key
modifier|*
name|private_key
parameter_list|,
name|char
modifier|*
modifier|*
name|comment_return
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

