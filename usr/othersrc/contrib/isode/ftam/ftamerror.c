begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftamerror.c - return FTAM error code in string form */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/ftam/RCS/ftamerror.c,v 7.1 91/02/22 09:22:50 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/ftam/RCS/ftamerror.c,v 7.1 91/02/22 09:22:50 mrose Interim $  *  *  * $Log:	ftamerror.c,v $  * Revision 7.1  91/02/22  09:22:50  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:53:34  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ftam.h"
end_include

begin_comment
comment|/*
comment|DATA */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_gen
index|[]
init|=
block|{
literal|"No reason"
block|,
literal|"Responder error (unspecific)"
block|,
literal|"System shutdown"
block|,
literal|"FTAM management problem (unspecific)"
block|,
literal|"FTAM management, bad account"
block|,
literal|"FTAM management, security not passed"
block|,
literal|"Delay may be encountered"
block|,
literal|"Initiator error (unspecific)"
block|,
literal|"Subsequent error"
block|,
literal|"Temporal insufficiency of resources"
block|,
literal|"Access request violates VFS security"
block|,
literal|"Access request violates local security"
block|,
literal|"Indications waiting"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_gen_cnt
init|=
sizeof|sizeof
name|diag_gen
operator|/
sizeof|sizeof
name|diag_gen
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_pro
index|[]
init|=
block|{
literal|"Conflicting parameter values"
block|,
literal|"Unsupported parameter values"
block|,
literal|"Mandatory parameter not set"
block|,
literal|"Unsupported parameter"
block|,
literal|"Duplicated parameter"
block|,
literal|"Illegal parameter type"
block|,
literal|"Unsupported parameter type"
block|,
literal|"FTAM protocol error (unspecific)"
block|,
literal|"FTAM protocol error, procedure error"
block|,
literal|"FTAM protocol error, functional unit error"
block|,
literal|"FTAM protocol error, corruption error"
block|,
literal|"Lower layer failure"
block|,
literal|"Lower layer addressing error"
block|,
literal|"Timeout"
block|,
literal|"System shutdown"
block|,
literal|"Illegal grouping sequence"
block|,
literal|"Grouping threshold violation"
block|,
literal|"Specific PDU request inconsistent with the current requested access"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_pro_cnt
init|=
sizeof|sizeof
name|diag_pro
operator|/
sizeof|sizeof
name|diag_pro
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_acs
index|[]
init|=
block|{
literal|"Association with user not allowed"
block|,
literal|"not assigned, #2001"
block|,
literal|"Unsupported service class"
block|,
literal|"Unsupported functional unit"
block|,
literal|"Attribute group error (unspecific)"
block|,
literal|"Attribute group not supported"
block|,
literal|"Attribute group not allowed"
block|,
literal|"Bad account"
block|,
literal|"Association management (unspecific)"
block|,
literal|"Association management - bad address"
block|,
literal|"Association management - bad account"
block|,
literal|"Checkpoint window error - too large"
block|,
literal|"Checkpoint window error - too small"
block|,
literal|"Checkpoint window error - unsupported"
block|,
literal|"Communications QoS not supported"
block|,
literal|"Initiator identity unacceptable"
block|,
literal|"Context management refused"
block|,
literal|"Rollback not available"
block|,
literal|"Contents type list cut by responder"
block|,
literal|"Contents type list cut by Presentation service"
block|,
literal|"Invalid filestore password"
block|,
literal|"Incompatible service classes"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_acs_cnt
init|=
sizeof|sizeof
name|diag_acs
operator|/
sizeof|sizeof
name|diag_acs
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_sel
index|[]
init|=
block|{
literal|"Filename not found"
block|,
literal|"Selection attributes not matched"
block|,
literal|"Initial attributes not possible"
block|,
literal|"Bad attribute name"
block|,
literal|"Non-existent file"
block|,
literal|"File already exists"
block|,
literal|"File can not be created"
block|,
literal|"File can not be deleted"
block|,
literal|"Concurrency control not available"
block|,
literal|"Concurrency control not supported"
block|,
literal|"Concurrency control not possible"
block|,
literal|"More restrictive lock"
block|,
literal|"File busy"
block|,
literal|"File not available"
block|,
literal|"Access control not available"
block|,
literal|"Access control not supported"
block|,
literal|"Access control inconsistent"
block|,
literal|"Filename truncated"
block|,
literal|"Initial attributes altered"
block|,
literal|"Bad account"
block|,
literal|"Override selected existing file"
block|,
literal|"Override deleted and recreated file with old attributes"
block|,
literal|"Create override deleted and recreated file with new attributes"
block|,
literal|"Create override - not possible"
block|,
literal|"Ambiguous file specification"
block|,
literal|"Invalid create password"
block|,
literal|"Invalid delete password on override"
block|,
literal|"Bad attribute value"
block|,
literal|"Requested access violates permitted actions"
block|,
literal|"Functional unit not available for requested access"
block|,
literal|"File created but not selected"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_sel_cnt
init|=
sizeof|sizeof
name|diag_sel
operator|/
sizeof|sizeof
name|diag_sel
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_mgt
index|[]
init|=
block|{
literal|"Attribute non-existant"
block|,
literal|"Attribute cannot be read"
block|,
literal|"Attribute cannot be changed"
block|,
literal|"Attribute not supported"
block|,
literal|"Bad attribute name"
block|,
literal|"Bad attribute value"
block|,
literal|"Attribute partially supported"
block|,
literal|"Additional set attribute not distinct"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_mgt_cnt
init|=
sizeof|sizeof
name|diag_mgt
operator|/
sizeof|sizeof
name|diag_mgt
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_acc
index|[]
init|=
block|{
literal|"Bad FADU (unspecific)"
block|,
literal|"Bad FADU - size error"
block|,
literal|"Bad FADU - type error"
block|,
literal|"Bad FADU - poorly specified"
block|,
literal|"Bad FADU - bad location"
block|,
literal|"FADU does not exist"
block|,
literal|"FADU not available (unspecific)"
block|,
literal|"FADU not available for reading"
block|,
literal|"FADU not available for writing"
block|,
literal|"FADU not available for location"
block|,
literal|"FADU not available for erasure"
block|,
literal|"FADU cannot be inserted"
block|,
literal|"FADU cannot be replaced"
block|,
literal|"FADU cannot be located"
block|,
literal|"Bad data element type"
block|,
literal|"Operation not available"
block|,
literal|"Operation not supported"
block|,
literal|"Operation inconsistent"
block|,
literal|"Concurrency control not available"
block|,
literal|"Concurrency control not supported"
block|,
literal|"Concurrency control inconsistent"
block|,
literal|"Processing mode not available"
block|,
literal|"Processing mode not supported"
block|,
literal|"Processing mode inconsistent"
block|,
literal|"Access context not available"
block|,
literal|"Access context not supported"
block|,
literal|"Bad write (unspecific)"
block|,
literal|"Bad read (unspecific)"
block|,
literal|"Local failure (unspecific)"
block|,
literal|"Local failure - file space exhausted"
block|,
literal|"Local failure - data corrupted"
block|,
literal|"Local failure - device failure"
block|,
literal|"Future file size exceeded"
block|,
literal|"not assigned, #5033"
block|,
literal|"Future file size increased"
block|,
literal|"Functional unit invalid in processing mode"
block|,
literal|"Contents type inconsistent"
block|,
literal|"Contents type simplified"
block|,
literal|"Duplicate FADU name"
block|,
literal|"Damage to select/open regime"
block|,
literal|"FADU locking not available on file"
block|,
literal|"FADU locked by another user"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_acc_cnt
init|=
sizeof|sizeof
name|diag_acc
operator|/
sizeof|sizeof
name|diag_acc
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|diag_rvy
index|[]
init|=
block|{
literal|"Bad checkpoint (unspecific)"
block|,
literal|"Activity not unique"
block|,
literal|"Checkpoint outside window"
block|,
literal|"Activity no longer exists"
block|,
literal|"Activity not recognized"
block|,
literal|"No docket"
block|,
literal|"Corrupt docket"
block|,
literal|"File waiting restart"
block|,
literal|"Bad recovery point"
block|,
literal|"Non-existent recovery point"
block|,
literal|"Recovery mode not available"
block|,
literal|"Recovery mode inconsistent"
block|,
literal|"Recovery mode reduced"
block|,
literal|"Access control not available"
block|,
literal|"Access control not supported"
block|,
literal|"Access control inconsistent"
block|,
literal|"Contents type inconsistent"
block|,
literal|"Contents type simplified"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|diag_rvy_cnt
init|=
sizeof|sizeof
name|diag_rvy
operator|/
sizeof|sizeof
name|diag_rvy
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|char
modifier|*
name|FErrString
parameter_list|(
name|code
parameter_list|)
specifier|register
name|int
name|code
decl_stmt|;
block|{
specifier|register
name|int
name|offset
decl_stmt|;
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|offset
operator|=
name|FS_CODE2OFF
argument_list|(
name|code
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|code
operator|-
name|offset
condition|)
block|{
case|case
name|FS_GEN_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_gen_cnt
condition|)
return|return
name|diag_gen
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_PRO_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_pro_cnt
condition|)
return|return
name|diag_pro
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_ACS_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_acs_cnt
condition|)
return|return
name|diag_acs
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_SEL_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_sel_cnt
condition|)
return|return
name|diag_sel
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_MGT_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_mgt_cnt
condition|)
return|return
name|diag_mgt
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_ACC_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_acc_cnt
condition|)
return|return
name|diag_acc
index|[
name|offset
index|]
return|;
break|break;
case|case
name|FS_RVY_BASE
case|:
if|if
condition|(
name|offset
operator|<
name|diag_rvy_cnt
condition|)
return|return
name|diag_rvy
index|[
name|offset
index|]
return|;
break|break;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"unknown error code %d"
argument_list|,
name|code
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function

end_unit

