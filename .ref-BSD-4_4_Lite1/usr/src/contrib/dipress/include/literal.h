begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Interpress utilities  *  * Copyright (c) 1984, 1985, 1986 Xerox Corp.  *  * HISTORY   * 17-Jun-86  Lee Moore (lee) at Xerox Webster Research Center  *	Added warning about Op() macro.  *  *  *  Written for Xerox Corporation by William LeFebvre  *  30-May-1984  *  */
end_comment

begin_comment
comment|/*  *  Subroutines to help build interpress files:  *  *  literal interface level - these routines produce interpress output at  *			      the token level.  */
end_comment

begin_comment
comment|/*  *  This file contains the macro definitions for some of the literal  *  operations.  This is done for efficiency reasons.  */
end_comment

begin_define
define|#
directive|define
name|append_short_number
parameter_list|(
name|number
parameter_list|)
define|\
value|append_n_byte_int((long)(number + INTEGER_ZERO), 2)
end_define

begin_define
define|#
directive|define
name|AppendIdentifier
parameter_list|(
name|string
parameter_list|)
define|\
value|append_Sequence(sequenceIdentifier, strlen(string), (unsigned char *)string)
end_define

begin_define
define|#
directive|define
name|AppendString
parameter_list|(
name|string
parameter_list|)
define|\
value|append_Sequence(sequenceString, strlen(string), (unsigned char *)string)
end_define

begin_define
define|#
directive|define
name|AppendComment
parameter_list|(
name|string
parameter_list|)
define|\
value|append_Sequence(sequenceComment, strlen(string), (unsigned char *)string)
end_define

begin_define
define|#
directive|define
name|AppendInsertFile
parameter_list|(
name|string
parameter_list|)
define|\
value|append_Sequence(sequenceInsertFile, strlen(string), (unsigned char *)string)
end_define

begin_comment
comment|/*  * An abbreviation for AppendOp:   *	using this guy is really a bad idea because it depends on a bug  *	in the C compiler.  While it will work for PCC, the Tartan compiler  *	will choke on it.  Don't use this feature if you want your code to  *	be portable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|Op
parameter_list|(
name|string
parameter_list|)
value|AppendOp((unsigned)OP_
comment|/**/
value|string)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Op
parameter_list|(
name|string
parameter_list|)
value|AppendOp(1)
end_define

begin_comment
comment|/* is this the right thing? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

