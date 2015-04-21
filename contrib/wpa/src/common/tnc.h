begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * TNC - Common defines  * Copyright (c) 2007-2014, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TNC_H
end_ifndef

begin_define
define|#
directive|define
name|TNC_H
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|TNC_UInt32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|TNC_BufferReference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_IMVID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_IMCID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_ConnectionID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_ConnectionState
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_RetryReason
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_IMV_Action_Recommendation
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_IMV_Evaluation_Result
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_MessageType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_MessageType
modifier|*
name|TNC_MessageTypeList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_VendorID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_Subtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_MessageSubtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_Version
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_Result
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_UInt32
name|TNC_AttributeID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCS_BindFunctionPointer
function_decl|)
parameter_list|(
name|TNC_IMVID
name|imvID
parameter_list|,
name|char
modifier|*
name|functionName
parameter_list|,
name|void
modifier|*
modifier|*
name|pOutfunctionPointer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCS_ReportMessageTypesPointer
function_decl|)
parameter_list|(
name|TNC_IMVID
name|imvID
parameter_list|,
name|TNC_MessageTypeList
name|supportedTypes
parameter_list|,
name|TNC_UInt32
name|typeCount
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCS_SendMessagePointer
function_decl|)
parameter_list|(
name|TNC_IMVID
name|imvID
parameter_list|,
name|TNC_ConnectionID
name|connectionID
parameter_list|,
name|TNC_BufferReference
name|message
parameter_list|,
name|TNC_UInt32
name|messageLength
parameter_list|,
name|TNC_MessageType
name|messageType
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCS_RequestHandshakeRetryPointer
function_decl|)
parameter_list|(
name|TNC_IMVID
name|imvID
parameter_list|,
name|TNC_ConnectionID
name|connectionID
parameter_list|,
name|TNC_RetryReason
name|reason
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCS_ProvideRecommendationPointer
function_decl|)
parameter_list|(
name|TNC_IMVID
name|imvID
parameter_list|,
name|TNC_ConnectionID
name|connectionID
parameter_list|,
name|TNC_IMV_Action_Recommendation
name|recommendation
parameter_list|,
name|TNC_IMV_Evaluation_Result
name|evaluation
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCC_BindFunctionPointer
function_decl|)
parameter_list|(
name|TNC_IMCID
name|imcID
parameter_list|,
name|char
modifier|*
name|functionName
parameter_list|,
name|void
modifier|*
modifier|*
name|pOutfunctionPointer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCC_SendMessagePointer
function_decl|)
parameter_list|(
name|TNC_IMCID
name|imcID
parameter_list|,
name|TNC_ConnectionID
name|connectionID
parameter_list|,
name|TNC_BufferReference
name|message
parameter_list|,
name|TNC_UInt32
name|messageLength
parameter_list|,
name|TNC_MessageType
name|messageType
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCC_ReportMessageTypesPointer
function_decl|)
parameter_list|(
name|TNC_IMCID
name|imcID
parameter_list|,
name|TNC_MessageTypeList
name|supportedTypes
parameter_list|,
name|TNC_UInt32
name|typeCount
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|TNC_Result
function_decl|(
modifier|*
name|TNC_TNCC_RequestHandshakeRetryPointer
function_decl|)
parameter_list|(
name|TNC_IMCID
name|imcID
parameter_list|,
name|TNC_ConnectionID
name|connectionID
parameter_list|,
name|TNC_RetryReason
name|reason
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|TNC_IFIMV_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|TNC_IFIMC_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_NOT_INITIALIZED
value|1
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_ALREADY_INITIALIZED
value|2
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_NO_COMMON_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_CANT_RETRY
value|4
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_WONT_RETRY
value|5
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_INVALID_PARAMETER
value|6
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_CANT_RESPOND
value|7
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_ILLEGAL_OPERATION
value|8
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_OTHER
value|9
end_define

begin_define
define|#
directive|define
name|TNC_RESULT_FATAL
value|10
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_CREATE
value|0
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_HANDSHAKE
value|1
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_ACCESS_ALLOWED
value|2
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_ACCESS_ISOLATED
value|3
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_ACCESS_NONE
value|4
end_define

begin_define
define|#
directive|define
name|TNC_CONNECTION_STATE_DELETE
value|5
end_define

begin_define
define|#
directive|define
name|TNC_VENDORID_ANY
value|((TNC_VendorID) 0xffffff)
end_define

begin_define
define|#
directive|define
name|TNC_SUBTYPE_ANY
value|((TNC_Subtype) 0xff)
end_define

begin_comment
comment|/* TNCC-TNCS Message Types */
end_comment

begin_define
define|#
directive|define
name|TNC_TNCCS_RECOMMENDATION
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TNC_TNCCS_ERROR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TNC_TNCCS_PREFERREDLANGUAGE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|TNC_TNCCS_REASONSTRINGS
value|0x00000004
end_define

begin_comment
comment|/* Possible TNC_IMV_Action_Recommendation values: */
end_comment

begin_enum
enum|enum
name|IMV_Action_Recommendation
block|{
name|TNC_IMV_ACTION_RECOMMENDATION_ALLOW
block|,
name|TNC_IMV_ACTION_RECOMMENDATION_NO_ACCESS
block|,
name|TNC_IMV_ACTION_RECOMMENDATION_ISOLATE
block|,
name|TNC_IMV_ACTION_RECOMMENDATION_NO_RECOMMENDATION
block|}
enum|;
end_enum

begin_comment
comment|/* Possible TNC_IMV_Evaluation_Result values: */
end_comment

begin_enum
enum|enum
name|IMV_Evaluation_Result
block|{
name|TNC_IMV_EVALUATION_RESULT_COMPLIANT
block|,
name|TNC_IMV_EVALUATION_RESULT_NONCOMPLIANT_MINOR
block|,
name|TNC_IMV_EVALUATION_RESULT_NONCOMPLIANT_MAJOR
block|,
name|TNC_IMV_EVALUATION_RESULT_ERROR
block|,
name|TNC_IMV_EVALUATION_RESULT_DONT_KNOW
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TNC_H */
end_comment

end_unit

