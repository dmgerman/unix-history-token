begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * common encoding macro definitions  */
end_comment

begin_define
define|#
directive|define
name|DO_OFFSET
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|((parm) + (p)->pe_ucode)
end_define

begin_define
define|#
directive|define
name|NO_OFFSET
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(parm)
end_define

begin_comment
comment|/* various things From Pointer And Offset- *_FPAO */
end_comment

begin_define
define|#
directive|define
name|INT_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(integer *)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|REAL_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(double *)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|CHAR_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(char *)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|OID_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(OID *)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|SOID_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|((OID)NO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|PTR_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(char **)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|SPTR_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|((char *)NO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|QB_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(struct qbuf **)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|SQB_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|((struct qbuf *)NO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|PE_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|(*(PE *)DO_OFFSET(parm, p))
end_define

begin_define
define|#
directive|define
name|SPE_FPAO
parameter_list|(
name|parm
parameter_list|,
name|p
parameter_list|)
value|((PE)NO_OFFSET(parm, p)
end_define

begin_define
define|#
directive|define
name|TYPE2MOD
parameter_list|(
name|mod
parameter_list|,
name|p
parameter_list|)
value|((mod)->md_etab[p->pe_tag])
end_define

end_unit

