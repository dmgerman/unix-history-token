begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  *	Routines to deal with the VMS User Authorization File:  *  *	get_vms_uaf_record(name,uaf);  *	validate_vms_user(name,password,uaf);  *	hash_vms_password(output_buf,input_buf,input_len,username,type,salt);  *  *  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Includes  */
end_comment

begin_include
include|#
directive|include
file|<vms/fab.h>
end_include

begin_comment
comment|/* File access block */
end_comment

begin_include
include|#
directive|include
file|<vms/rab.h>
end_include

begin_comment
comment|/* Record access block */
end_comment

begin_include
include|#
directive|include
file|<vms/rmsdef.h>
end_include

begin_comment
comment|/* RMS return codes */
end_comment

begin_include
include|#
directive|include
file|<vms/ssdef.h>
end_include

begin_comment
comment|/* System service return codes */
end_comment

begin_include
include|#
directive|include
file|<vms/uafdef.h>
end_include

begin_comment
comment|/* Authorization file records */
end_comment

begin_include
include|#
directive|include
file|<vms/logdef.h>
end_include

begin_comment
comment|/* Logical name table seach masks */
end_comment

begin_comment
comment|/*  * defines  */
end_comment

begin_define
define|#
directive|define
name|RETRY_RLK
value|2
end_define

begin_comment
comment|/* number of retries if record locked */
end_comment

begin_define
define|#
directive|define
name|SLEEP_RLK
value|75
end_define

begin_comment
comment|/* MS to sleep before retrying a GET */
end_comment

begin_define
define|#
directive|define
name|RECSIZ
value|80
end_define

begin_comment
comment|/* Maximum length for password string */
end_comment

begin_define
define|#
directive|define
name|UAFNAME
value|"SYSUAF"
end_define

begin_comment
comment|/* Name of authorization file */
end_comment

begin_define
define|#
directive|define
name|UAFSIZE
value|6
end_define

begin_comment
comment|/* Size of above */
end_comment

begin_define
define|#
directive|define
name|DEFNAME
value|"SYS$SYSTEM:.DAT"
end_define

begin_comment
comment|/* Default path to authorization file */
end_comment

begin_define
define|#
directive|define
name|DEFSIZE
value|15
end_define

begin_comment
comment|/* Size of above */
end_comment

begin_define
define|#
directive|define
name|DEFUSER
value|"DEFAULT     "
end_define

begin_comment
comment|/* "Default user" name */
end_comment

begin_define
define|#
directive|define
name|UAF$_NORMAL
value|1
end_define

begin_comment
comment|/* Normal completion */
end_comment

begin_define
define|#
directive|define
name|UAF$_INVUSR
value|-2
end_define

begin_comment
comment|/* Invalid User Name */
end_comment

begin_define
define|#
directive|define
name|UAF$_INVPWD
value|-4
end_define

begin_comment
comment|/* Invalid Password  */
end_comment

begin_define
define|#
directive|define
name|UAF$S_USERNAME
value|12
end_define

begin_comment
comment|/* User Name Size */
end_comment

begin_define
define|#
directive|define
name|UAF$S_PWD
value|8
end_define

begin_comment
comment|/* Password Size */
end_comment

begin_struct
struct|struct
name|descr
block|{
name|int
name|size
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* VMS descriptor		*/
end_comment

begin_comment
comment|/*  * OWN STORAGE:  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|wakedelta
index|[]
init|=
block|{
operator|-
literal|10
operator|*
literal|1000
operator|*
name|SLEEP_RLK
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  *  *	status = get_vms_uaf_record(name,uaf);  *  */
end_comment

begin_function
name|int
name|get_vms_uaf_record
parameter_list|(
name|name
parameter_list|,
name|uaf
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
specifier|register
name|struct
name|uaf
modifier|*
name|uaf
decl_stmt|;
block|{
name|struct
name|FAB
name|fab
decl_stmt|;
name|struct
name|RAB
name|rab
decl_stmt|;
name|unsigned
name|int
name|old_privs
index|[
literal|2
index|]
decl_stmt|,
name|new_privs
index|[
literal|2
index|]
decl_stmt|;
name|int
name|status
decl_stmt|;
name|int
name|default_user
init|=
literal|1
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cp1
decl_stmt|,
modifier|*
name|cp2
decl_stmt|;
comment|/* 	 *	Zero the fab and rab 	 */
name|bzero
argument_list|(
operator|&
name|fab
argument_list|,
sizeof|sizeof
argument_list|(
name|fab
argument_list|)
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|rab
argument_list|,
sizeof|sizeof
argument_list|(
name|rab
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 *	Setup the fab 	 */
name|fab
operator|.
name|fab$b_bid
operator|=
name|FAB$C_BID
expr_stmt|;
name|fab
operator|.
name|fab$b_bln
operator|=
sizeof|sizeof
argument_list|(
name|fab
argument_list|)
expr_stmt|;
name|fab
operator|.
name|fab$l_fna
operator|=
name|UAFNAME
expr_stmt|;
name|fab
operator|.
name|fab$b_fns
operator|=
name|UAFSIZE
expr_stmt|;
name|fab
operator|.
name|fab$l_dna
operator|=
name|DEFNAME
expr_stmt|;
name|fab
operator|.
name|fab$b_dns
operator|=
name|DEFSIZE
expr_stmt|;
name|fab
operator|.
name|fab$b_dsbmsk
operator|=
operator|(
literal|1
operator|<<
name|LOG$C_GROUP
operator|)
operator||
operator|(
literal|1
operator|<<
name|LOG$C_PROCESS
operator|)
expr_stmt|;
name|fab
operator|.
name|fab$b_fac
operator||=
name|FAB$M_GET
expr_stmt|;
name|fab
operator|.
name|fab$b_shr
operator|=
operator|(
name|FAB$M_GET
operator||
name|FAB$M_PUT
operator||
name|FAB$M_UPD
operator||
name|FAB$M_DEL
operator|)
expr_stmt|;
name|fab
operator|.
name|fab$b_org
operator|=
name|FAB$C_IDX
expr_stmt|;
name|fab
operator|.
name|fab$b_rfm
operator|=
name|FAB$C_VAR
expr_stmt|;
comment|/* 	 *	setup the rab 	 */
name|rab
operator|.
name|rab$b_bid
operator|=
name|RAB$C_BID
expr_stmt|;
name|rab
operator|.
name|rab$b_bln
operator|=
sizeof|sizeof
argument_list|(
name|rab
argument_list|)
expr_stmt|;
name|rab
operator|.
name|rab$b_rac
operator|=
name|RAB$C_KEY
expr_stmt|;
name|rab
operator|.
name|rab$l_rop
operator||=
name|RAB$M_NLK
expr_stmt|;
name|rab
operator|.
name|rab$b_mbc
operator|=
literal|10
expr_stmt|;
name|rab
operator|.
name|rab$w_usz
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|uaf
argument_list|)
expr_stmt|;
name|rab
operator|.
name|rab$l_ubf
operator|=
operator|(
name|char
operator|*
operator|)
name|uaf
expr_stmt|;
name|rab
operator|.
name|rab$l_kbfpbf
operator|.
name|rab$l_kbf
operator|=
operator|(
name|unsigned
name|long
name|int
operator|*
operator|)
name|uaf
expr_stmt|;
name|rab
operator|.
name|rab$b_kszpsz
operator|.
name|rab$b_ksz
operator|=
name|UAF$S_USERNAME
expr_stmt|;
name|rab
operator|.
name|rab$l_fab
operator|=
operator|&
name|fab
expr_stmt|;
comment|/* 	 *	Enable all privileges that we are authorized to have just to 	 *	enhance the possibility of accessing the SYSUAF file. 	 */
name|new_privs
index|[
literal|0
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|new_privs
index|[
literal|1
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|sys$setprv
argument_list|(
literal|1
argument_list|,
name|new_privs
argument_list|,
literal|0
argument_list|,
name|old_privs
argument_list|)
expr_stmt|;
comment|/* 	 *  Open the File and connect the RAB 	 */
name|status
operator|=
name|sys$open
argument_list|(
operator|&
name|fab
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|status
operator|&
literal|1
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|status
operator|==
name|RMS$_SNE
operator|)
operator|||
operator|(
name|status
operator|==
name|RMS$_SPE
operator|)
operator|||
operator|(
name|status
operator|==
name|RMS$_DME
operator|)
condition|)
block|{
name|fab
operator|.
name|fab$b_shr
operator|=
literal|0
expr_stmt|;
name|status
operator|=
name|sys$open
argument_list|(
operator|&
name|fab
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|status
operator|&
literal|1
operator|)
condition|)
goto|goto
name|exit
goto|;
block|}
else|else
goto|goto
name|exit
goto|;
block|}
name|status
operator|=
name|sys$connect
argument_list|(
operator|&
name|rab
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|status
operator|&
literal|1
operator|)
condition|)
goto|goto
name|exit
goto|;
comment|/* 	 *	Move the USERNAME to the uaf$t_username field (as a buffer) 	 *	uppercaseify it along the way and check it against the 	 *	username "DEFAULT" (which is not a real username).  Pad 	 *	the uaf$t_username field with blanks. 	 */
name|i
operator|=
name|UAF$S_USERNAME
expr_stmt|;
name|cp
operator|=
name|name
expr_stmt|;
name|cp1
operator|=
name|uaf
operator|->
name|uaf$t_username
expr_stmt|;
name|cp2
operator|=
name|DEFUSER
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
condition|)
break|break;
if|if
condition|(
operator|*
name|cp
operator|!=
operator|*
name|cp2
operator|++
condition|)
name|default_user
operator|=
literal|0
expr_stmt|;
operator|*
name|cp1
operator|++
operator|=
operator|(
operator|(
operator|*
name|cp
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|<=
literal|'z'
operator|)
operator|)
condition|?
operator|*
name|cp
operator|++
operator|+
operator|(
literal|'A'
operator|-
literal|'a'
operator|)
else|:
operator|*
name|cp
operator|++
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
operator|*
name|cp1
operator|++
operator|=
literal|' '
expr_stmt|;
if|if
condition|(
operator|*
name|cp2
operator|++
operator|!=
literal|' '
condition|)
name|default_user
operator|=
literal|0
expr_stmt|;
block|}
comment|/* 	 *	The "DEFAULT" user is illegal! 	 */
if|if
condition|(
name|default_user
condition|)
block|{
name|status
operator|=
name|UAF$_INVUSR
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
comment|/* 	 *	Look up the User's UAF record 	 */
name|status
operator|=
name|get_record
argument_list|(
operator|&
name|rab
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|RMS$_RNF
condition|)
name|status
operator|=
name|UAF$_INVUSR
expr_stmt|;
name|exit
label|:
comment|/* 	 *	Done: close the file, release privileges and return status 	 */
name|sys$disconnect
argument_list|(
operator|&
name|rab
argument_list|)
expr_stmt|;
name|sys$close
argument_list|(
operator|&
name|fab
argument_list|)
expr_stmt|;
name|sys$setprv
argument_list|(
literal|0
argument_list|,
name|new_privs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sys$setprv
argument_list|(
literal|1
argument_list|,
name|old_privs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	Read the record and deal with file locking  */
end_comment

begin_expr_stmt
specifier|static
name|get_record
argument_list|(
argument|rab
argument_list|)
expr|struct
name|RAB
operator|*
name|rab
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|retries
init|=
name|RETRY_RLK
decl_stmt|;
name|int
name|status
decl_stmt|;
comment|/* 	 *	Re-try the appropriate number of times 	 */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* 		 *	Get the record 		 */
name|status
operator|=
name|sys$get
argument_list|(
name|rab
argument_list|)
expr_stmt|;
comment|/* 		 *	If the return code is not "Record Locked" it is either 		 *	a success or error that we can't handle, return it. 		 */
if|if
condition|(
name|status
operator|!=
name|RMS$_RLK
condition|)
break|break;
comment|/* 		 *	Record Locked:  If retries exceeded, return error 		 */
if|if
condition|(
operator|--
name|retries
operator|<
literal|0
condition|)
break|break;
comment|/* 		 *	Retry: Sleep first 		 */
name|status
operator|=
name|sys$schdwk
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|wakedelta
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|&
literal|1
condition|)
name|sys$hiber
argument_list|()
expr_stmt|;
block|}
comment|/* 	 *	Done: Return status 	 */
return|return
operator|(
name|status
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  *  *	Validate a UserName/Password pair and return the user's UAF record  *  */
end_comment

begin_function
name|int
name|validate_vms_user
parameter_list|(
name|name
parameter_list|,
name|password
parameter_list|,
name|uaf
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|password
decl_stmt|;
specifier|register
name|struct
name|uaf
modifier|*
name|uaf
decl_stmt|;
block|{
name|char
name|password_buf
index|[
name|RECSIZ
index|]
decl_stmt|;
name|char
name|username_buf
index|[
name|UAF$S_USERNAME
index|]
decl_stmt|;
name|char
name|encrypt_buf
index|[
name|UAF$S_PWD
index|]
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cp1
decl_stmt|;
comment|/* 	 *	Get the User's UAF record 	 */
name|i
operator|=
name|get_vms_uaf_record
argument_list|(
name|name
argument_list|,
name|uaf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|i
operator|&
literal|1
operator|)
condition|)
return|return
operator|(
name|i
operator|)
return|;
comment|/* 	 *	Limit the username to "UAF$S_USERNAME" size while copying and 	 *	uppercasifying it.  Pad with spaces to "UAF$S_USERNAME" size. 	 */
name|i
operator|=
name|UAF$S_USERNAME
expr_stmt|;
name|cp
operator|=
name|name
expr_stmt|;
name|cp1
operator|=
name|username_buf
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
condition|)
break|break;
operator|*
name|cp1
operator|++
operator|=
operator|(
operator|(
operator|*
name|cp
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|<=
literal|'z'
operator|)
operator|)
condition|?
operator|*
name|cp
operator|++
operator|+
operator|(
literal|'A'
operator|-
literal|'a'
operator|)
else|:
operator|*
name|cp
operator|++
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
operator|*
name|cp1
operator|++
operator|=
literal|' '
expr_stmt|;
comment|/* 	 *	Limit the password to "RECSIZ" size while copying and 	 *	uppercasifying it. 	 */
name|i
operator|=
name|RECSIZ
expr_stmt|;
name|cp
operator|=
name|password
expr_stmt|;
name|cp1
operator|=
name|password_buf
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|==
literal|0
condition|)
break|break;
operator|*
name|cp1
operator|++
operator|=
operator|(
operator|(
operator|*
name|cp
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|<=
literal|'z'
operator|)
operator|)
condition|?
operator|*
name|cp
operator|++
operator|+
operator|(
literal|'A'
operator|-
literal|'a'
operator|)
else|:
operator|*
name|cp
operator|++
expr_stmt|;
block|}
name|i
operator|=
operator|(
name|RECSIZ
operator|-
literal|1
operator|)
operator|-
name|i
expr_stmt|;
comment|/* Compute size of password string */
comment|/* 	 *	Encrypt the password 	 */
name|hash_vms_password
argument_list|(
name|encrypt_buf
argument_list|,
name|password_buf
argument_list|,
name|i
argument_list|,
name|username_buf
argument_list|,
name|uaf
operator|->
name|uaf$b_encrypt
argument_list|,
name|uaf
operator|->
name|uaf$w_salt
argument_list|)
expr_stmt|;
if|if
condition|(
name|bcmp
argument_list|(
name|encrypt_buf
argument_list|,
name|uaf
operator|->
name|uaf$l_pwd
argument_list|,
name|UAF$S_PWD
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|UAF$_NORMAL
operator|)
return|;
else|else
return|return
operator|(
name|UAF$_INVPWD
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  *  *	PASSWORD SMASHING CODE:  *		The real bit hacking is done in "asm" statements, since  *		"C" is poorly suited towards quad-word arithmetic!  *  */
end_comment

begin_comment
comment|/*  *	AUTODIN II CRC Coefficients:  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|autodin
index|[]
init|=
block|{
literal|000000000000
block|,
literal|003555610144
block|,
literal|007333420310
block|,
literal|004666230254
block|,
literal|016667040620
block|,
literal|015332650764
block|,
literal|011554460530
block|,
literal|012001270474
block|,
literal|035556101440
block|,
literal|036003711504
block|,
literal|032665521750
block|,
literal|031330331614
block|,
literal|023331141260
block|,
literal|020664751324
block|,
literal|024002561170
block|,
literal|027557371034
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	PURDY Polynomial Coefficients  */
end_comment

begin_decl_stmt
specifier|static
name|long
name|c
index|[]
init|=
block|{
operator|-
literal|83
block|,
operator|-
literal|1
block|,
comment|/* C1 */
operator|-
literal|179
block|,
operator|-
literal|1
block|,
comment|/* C2 */
operator|-
literal|257
block|,
operator|-
literal|1
block|,
comment|/* C3 */
operator|-
literal|323
block|,
operator|-
literal|1
block|,
comment|/* C4 */
operator|-
literal|363
block|,
operator|-
literal|1
comment|/* C5 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Hashing routine  */
end_comment

begin_macro
name|hash_vms_password
argument_list|(
argument|output_buf
argument_list|,
argument|input_buf
argument_list|,
argument|input_length
argument_list|,
argument|username
argument_list|,
argument|type
argument_list|,
argument|salt
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|output_buf
decl_stmt|,
modifier|*
name|input_buf
decl_stmt|,
modifier|*
name|username
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|salt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* 	 *	Dispatch on encryption type 	 */
if|if
condition|(
name|type
operator|==
literal|0
condition|)
block|{
comment|/* 		 *	AUTODIN II CRC: 		 */
name|crc
argument_list|(
name|autodin
argument_list|,
operator|-
literal|1
argument_list|,
name|input_length
argument_list|,
name|input_buf
argument_list|,
name|output_buf
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
comment|/* 		 *	PURDY: 		 */
name|i
operator|=
literal|8
expr_stmt|;
name|cp
operator|=
name|output_buf
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* Init output buffer */
comment|/* 		 *	Collapse the password into a quadword 		 */
name|collapse
argument_list|(
name|input_length
argument_list|,
name|input_buf
argument_list|,
name|output_buf
argument_list|)
expr_stmt|;
comment|/* 		 *	Add salt to middle of quadword 		 */
operator|*
operator|(
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|(
name|output_buf
operator|+
literal|3
operator|)
operator|)
operator|+=
name|salt
expr_stmt|;
comment|/* 		 *	Collapse the username into the quadword 		 */
name|collapse
argument_list|(
comment|/*UAF$S_USERNAME*/
literal|12
argument_list|,
name|username
argument_list|,
name|output_buf
argument_list|)
expr_stmt|;
comment|/* 		 *	Compute the PURDY polynomial: 		 */
name|purdy
argument_list|(
name|output_buf
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  *	CRC routine:  */
end_comment

begin_expr_stmt
specifier|static
name|crc
argument_list|(
argument|table
argument_list|,
argument|initial_crc
argument_list|,
argument|input_len
argument_list|,
argument|input_buf
argument_list|,
argument|output_buf
argument_list|)
block|{
name|asm
argument_list|(
literal|"	crc	*4(ap),8(ap),12(ap),*16(ap)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	clrl	r1"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	movq	r0,*20(ap)"
argument_list|)
block|; }
comment|/*  *	Routine to collapse a string into a quadword:  */
specifier|static
name|collapse
argument_list|(
name|input_len
argument_list|,
name|input_buf
argument_list|,
name|output_buf
argument_list|)
specifier|register
name|unsigned
name|char
operator|*
name|input_buf
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|input_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|unsigned
name|char
modifier|*
name|output_buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|input_len
operator|>
literal|0
condition|)
block|{
name|output_buf
index|[
name|input_len
operator|&
operator|~
operator|(
operator|-
literal|8
operator|)
index|]
operator|+=
operator|*
name|input_buf
operator|++
expr_stmt|;
name|input_len
operator|--
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  *  *	GROMMY STUFF TO COMPUTE THE PURDY POLYNOMIAL  *  */
end_comment

begin_expr_stmt
specifier|static
name|purdy
argument_list|(
argument|U
argument_list|,
argument|C
argument_list|)
block|{
comment|/*  * This routine computes f(U) = p(U) mod P.  Where P is a prime of the form  * P = 2^64 - a.  The function p is the following polynomial:  * X^n0 + X^n1*C1 + X^3*C2 + X^2*C3 + X*C4 + C5  * The input U is an unsigned quadword.  */
name|asm
argument_list|(
literal|"	.set	A,59"
argument_list|)
block|;
comment|/* 2^64 -59 is the biggest quad prime */
name|asm
argument_list|(
literal|"	movq	*4(ap),-(sp)"
argument_list|)
block|;
comment|/* Push U */
name|asm
argument_list|(
literal|"	bsbw	PQMOD_R0"
argument_list|)
block|;
comment|/* Ensure U less than P */
name|asm
argument_list|(
literal|"	movaq	(sp),r4"
argument_list|)
block|;
comment|/* Maintain a pointer to X*/
name|asm
argument_list|(
literal|"	pushl	8(ap)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	movl	(sp)+,r5"
argument_list|)
block|;
comment|/* Point to the table of coefficients */
name|asm
argument_list|(
literal|"	movq	(r4),-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	$((1<<24)-63)"
argument_list|)
block|;
comment|/* n1 */
name|asm
argument_list|(
literal|"	bsbb	PQEXP_R3"
argument_list|)
block|;
comment|/* X^n1 */
name|asm
argument_list|(
literal|"	movq	(r4),-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	$((1<<24)-3)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	subl2	$((1<<24)-63),(sp)"
argument_list|)
block|;
comment|/* n0-n1 */
name|asm
argument_list|(
literal|"	bsbb	PQEXP_R3"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	movq	(r5)+,-(sp)"
argument_list|)
block|;
comment|/* C1 */
name|asm
argument_list|(
literal|"	bsbw	PQADD_R0"
argument_list|)
block|;
comment|/* X^(n0 - n1) + C1 */
name|asm
argument_list|(
literal|"	bsbw	PQMUL_R2"
argument_list|)
block|;
comment|/* X^n0 + X^n1*C1 */
name|asm
argument_list|(
literal|"	movq	(r5)+,-(sp)"
argument_list|)
block|;
comment|/* C2 */
name|asm
argument_list|(
literal|"	movq	(r4),-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbw	PQMUL_R2"
argument_list|)
block|;
comment|/* X*C2 */
name|asm
argument_list|(
literal|"	movq	(r5)+,-(sp)"
argument_list|)
block|;
comment|/* C3 */
name|asm
argument_list|(
literal|"	bsbw	PQADD_R0"
argument_list|)
block|;
comment|/* X*C2 + C3 */
name|asm
argument_list|(
literal|"	movq	(r4),-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMUL_R2"
argument_list|)
block|;
comment|/* X^2*C2 + X*C3 */
name|asm
argument_list|(
literal|"	movq	(r5)+,-(sp)"
argument_list|)
block|;
comment|/* C4 */
name|asm
argument_list|(
literal|"	bsbw	PQADD_R0"
argument_list|)
block|;
comment|/* X^2*C2 + X*C3 + C4 */
name|asm
argument_list|(
literal|"	movq	(r4),-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMUL_R2"
argument_list|)
block|;
comment|/* X^3*C2 + X^2*C3 + C4*X */
name|asm
argument_list|(
literal|"	movq	(r5)+,-(sp)"
argument_list|)
block|;
comment|/* C5 */
name|asm
argument_list|(
literal|"	bsbw	PQADD_R0"
argument_list|)
block|;
comment|/* X^3*C2 + X^2*C3 + C4*X + C5 */
name|asm
argument_list|(
literal|"	bsbw	PQADD_R0"
argument_list|)
block|;
comment|/* Add in the high order terms */
name|asm
argument_list|(
literal|"	movq	(sp)+,*4(ap)"
argument_list|)
block|;
comment|/* Replace U with f(X) */
name|asm
argument_list|(
literal|"	movl	$1,r0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	ret"
argument_list|)
block|;
comment|/*  Replaces the inputs with U^n mod P where P is of the form */
comment|/*  P = 2^64 - a. */
comment|/* U is a quadword, n is an unsigned longword. */
name|asm
argument_list|(
literal|"PQEXP_R3:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	popr	$8"
argument_list|)
block|;
comment|/* Record return address */
name|asm
argument_list|(
literal|"	movq	$1,-(sp)"
argument_list|)
block|;
comment|/* Initialize */
name|asm
argument_list|(
literal|"	movq	8+4(sp),-(sp)"
argument_list|)
block|;
comment|/* Copy U to top of stack for speed */
name|asm
argument_list|(
literal|"	tstl	8+8(sp)"
argument_list|)
block|;
comment|/* Only handle n greater than */
name|asm
argument_list|(
literal|"	beqlu	3f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"1:	blbc	8+8(sp),2f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	movq	(sp),-(sp)"
argument_list|)
block|;
comment|/* Copy the current power of U */
name|asm
argument_list|(
literal|"	movq	8+8(sp),-(sp)"
argument_list|)
block|;
comment|/* Multiply with current value */
name|asm
argument_list|(
literal|"	bsbb	PQMUL_R2"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	movq	(sp)+,8(sp)"
argument_list|)
block|;
comment|/* Replace current value */
name|asm
argument_list|(
literal|"	cmpzv	$1,$31,8+8(sp),$0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	beqlu	3f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"2:	movq	(sp),-(sp)"
argument_list|)
block|;
comment|/* Proceed to next power of U */
name|asm
argument_list|(
literal|"	bsbb	PQMUL_R2"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	extzv	$1,$31,8+8(sp),8+8(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	brb	1b"
argument_list|)
block|;
name|asm
argument_list|(
literal|"3:	movq	8(sp),8+8+4(sp)"
argument_list|)
block|;
comment|/* Copy the return value */
name|asm
argument_list|(
literal|"	movaq	8+8+4(sp),sp"
argument_list|)
block|;
comment|/* Discard the exponent */
name|asm
argument_list|(
literal|"	jmp	(r3)"
argument_list|)
block|;
comment|/* return */
comment|/* Replaces the quadword U on the stack with U mod P where P is of the */
comment|/* form P = 2^64 - a. */
name|asm
argument_list|(
literal|"	.set	U,0"
argument_list|)
block|;
comment|/* Low  longword of U */
name|asm
argument_list|(
literal|"	.set	V,U+4"
argument_list|)
block|;
comment|/* High longword of U */
name|asm
argument_list|(
literal|"	.set	Y,U+8"
argument_list|)
block|;
comment|/* Low  longword of Y */
name|asm
argument_list|(
literal|"	.set	Z,Y+4"
argument_list|)
block|;
comment|/* High longword of Y */
name|asm
argument_list|(
literal|"PQMOD_R0:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	popr	$1"
argument_list|)
block|;
comment|/* Record return address */
name|asm
argument_list|(
literal|"	cmpl	V(sp),$-1"
argument_list|)
block|;
comment|/* Replace U with U mod P */
name|asm
argument_list|(
literal|"	blssu	1f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	cmpl	U(sp),$-A"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	blssu	1f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	addl2	$A,U(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	adwc	$0,V(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"1:	jmp	(r0)"
argument_list|)
block|;
comment|/* return */
comment|/* Computes the product U*Y mod P where P is of the form 	 * P = 2^64 - a.  U, Y are quadwords less than P.  The product 	 * replaces U and Y on the stack. 	 * 	 * The product may be formed as the sum of four longword 	 * multiplications which are scaled by powers of 2^32 by evaluating: 	 * 2^64*v*z + 2^32*(v*y + u*z) + u*y 	 * The result is computed such that division by the modulus P 	 * is avoided. 	 */
name|asm
argument_list|(
literal|"PQMUL_R2:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	popr	$2"
argument_list|)
block|;
comment|/* Record return address */
name|asm
argument_list|(
literal|"	movl	sp,r2"
argument_list|)
block|;
comment|/* Record initial stack value */
name|asm
argument_list|(
literal|"	pushl	Z(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	V(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	EMULQ"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMOD_R0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQLSH_R0"
argument_list|)
block|;
comment|/* Obtain 2^32*v*z */
name|asm
argument_list|(
literal|"	pushl	Y(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	V(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	EMULQ"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMOD_R0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	Z(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	U(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	EMULQ"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMOD_R0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQADD_R0"
argument_list|)
block|;
comment|/* Obtain (v*y + u*z) */
name|asm
argument_list|(
literal|"	bsbb	PQADD_R0"
argument_list|)
block|;
comment|/* Add in 2^32*v*z */
name|asm
argument_list|(
literal|"	bsbb	PQLSH_R0"
argument_list|)
block|;
comment|/* Obtain the first two terms */
name|asm
argument_list|(
literal|"	pushl	Y(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	U(r2)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	EMULQ"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	PQMOD_R0"
argument_list|)
block|;
comment|/* Obtain the third term:  u*y */
name|asm
argument_list|(
literal|"	bsbb	PQADD_R0"
argument_list|)
block|;
comment|/* Add it in */
name|asm
argument_list|(
literal|"	movq	(sp)+,Y(r2)"
argument_list|)
block|;
comment|/* Copy the return value */
name|asm
argument_list|(
literal|"	movaq	Y(r2),sp"
argument_list|)
block|;
comment|/* Point the stack to the return value */
name|asm
argument_list|(
literal|"	jmp	(r1)"
argument_list|)
block|;
comment|/* return */
comment|/* This routine knows how to multiply two unsigned longwords, 	 * replacing them with the unsigned quadword product on the stack. 	 */
name|asm
argument_list|(
literal|"EMULQ:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	emul	4(sp),8(sp),$0,-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	clrl	-(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	tstl	4+8+4(sp)"
argument_list|)
block|;
comment|/* Check both longwords to see if we */
name|asm
argument_list|(
literal|"	bgeq	1f"
argument_list|)
block|;
comment|/* must compensate for the unsigned 								bias. */
name|asm
argument_list|(
literal|"	addl2	4+8+8(sp),(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"1:	tstl	4+8+8(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bgeq	2f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	addl2	4+8+4(sp),(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"2:	addl2	(sp)+,4(sp)"
argument_list|)
block|;
comment|/* Add in the compensation. */
name|asm
argument_list|(
literal|"	movq	(sp)+,4(sp)"
argument_list|)
block|;
comment|/* Replace the longwords with their 							product. */
name|asm
argument_list|(
literal|"	rsb"
argument_list|)
block|;
comment|/* 	 * Computes the product 2^32*U mod P where P is of the form 	 * P = 2^64 - a.  U is a quadword less than P.  The product replaces 	 * U on the stack. 	 * 	 * This routine is used by PQMUL in the formation of quadword 	 * products in such a way as to avoid division by the modulus P. 	 * The product 2^64*v + 2^32*u is congruent a*v + 2^32*u mod P 	 * (where u, v are longwords). 	 */
name|asm
argument_list|(
literal|"PQLSH_R0:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	popr	$1"
argument_list|)
block|;
comment|/* Record return address */
name|asm
argument_list|(
literal|"	pushl	V(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	pushl	$A"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	bsbb	EMULQ"
argument_list|)
block|;
comment|/* Push a*v */
name|asm
argument_list|(
literal|"	ashq	$32,Y(sp),Y(sp)"
argument_list|)
block|;
comment|/* Form Y = 2^32*u */
name|asm
argument_list|(
literal|"	brb	PQADD_R0_1"
argument_list|)
block|;
comment|/* Return the sum U + Y mod P. */
comment|/* 	 * Computes the sum U + Y mod P where P is of the form P = 2^64 - a. 	 * U, Y are quadwords less than P.  The sum replaces U and Y on 	 * the stack. 	 */
name|asm
argument_list|(
literal|"PQADD_R0:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	popr	$1"
argument_list|)
block|;
comment|/* Record return address */
name|asm
argument_list|(
literal|"PQADD_R0_1:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	addl2	U(sp),Y(sp)"
argument_list|)
comment|/* Add the low longwords */
name|asm
argument_list|(
literal|"	adwc	V(sp),Z(sp)"
argument_list|)
block|;
comment|/* Add the high longwords with the carry */
name|asm
argument_list|(
literal|"	bcs	2f"
argument_list|)
block|;
comment|/* If the result is greater than a quadword */
name|asm
argument_list|(
literal|"	cmpl	Z(sp),$-1"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	blssu	3f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	cmpl	Y(sp),$-A"
argument_list|)
block|;
comment|/* or simply greater than or equal to P */
name|asm
argument_list|(
literal|"	blssu	3f"
argument_list|)
block|;
name|asm
argument_list|(
literal|"2:	addl2	$A,Y(sp)"
argument_list|)
block|;
comment|/* we must subtract P.*/
name|asm
argument_list|(
literal|"	adwc	$0,Z(sp)"
argument_list|)
block|;
name|asm
argument_list|(
literal|"3:	movaq	Y(sp),sp"
argument_list|)
block|;
comment|/* Point the stack to the return value */
name|asm
argument_list|(
literal|"	jmp	(r0)"
argument_list|)
block|;
comment|/* return */
block|}
end_expr_stmt

end_unit

