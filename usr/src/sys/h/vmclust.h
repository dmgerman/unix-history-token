begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmclust.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Page clustering macros.  *   * dirtycl(pte)			is the page cluster dirty?  * anycl(pte,fld)		does any pte in the cluster has fld set?  * zapcl(pte,fld) = val		set all fields fld in the cluster to val  * distcl(pte)			distribute high bits to cluster; note that  *				distcl copies everything but pg_pfnum,  *				INCLUDING pg_m!!!  *  * In all cases, pte must be the low pte in the cluster, even if  * the segment grows backwards (e.g. the stack).  */
end_comment

begin_define
define|#
directive|define
name|H
parameter_list|(
name|pte
parameter_list|)
value|((struct hpte *)(pte))
end_define

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|dirty(pte)
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld)
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)->fld
end_define

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
value|(dirty(pte) || dirty((pte)+1))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|((pte)->fld || (((pte)+1)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
value|(pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|dirtycl
parameter_list|(
name|pte
parameter_list|)
define|\
value|(dirty(pte) || dirty((pte)+1) || dirty((pte)+2) || dirty((pte)+3))
end_define

begin_define
define|#
directive|define
name|anycl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|((pte)->fld || (((pte)+1)->fld) || (((pte)+2)->fld) || (((pte)+3)->fld))
end_define

begin_define
define|#
directive|define
name|zapcl
parameter_list|(
name|pte
parameter_list|,
name|fld
parameter_list|)
define|\
value|(pte)[3].fld = (pte)[2].fld = (pte)[1].fld = (pte)[0].fld
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|distcl
end_ifndef

begin_define
define|#
directive|define
name|distcl
parameter_list|(
name|pte
parameter_list|)
value|zapcl(H(pte),pg_high)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

