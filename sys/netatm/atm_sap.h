begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Services definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_SAP_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_SAP_H
end_define

begin_comment
comment|/*  * Service Access Point (SAP)  *  * A SAP specifies the definition of an interface used between two adjacent  * layers.  The SAP is named for the services the lower layer provides to   * the upper layer.  *  * The types of SAPs used are:  * 	Stack - defines the interfaces between stack service entities.  *		These are further divided into:  *  *		Stack class SAP - which identifies the type of interface  *			used.  All SAPs of a particular class will provide  *			the same interface services to the higher layer.  *			All stack command codes are constructed using class  *			SAP values.  *  *		Stack instance SAP - which identifies the specific identity  *			of the layer providing the class interface.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|Sap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAP_TYPE_MASK
value|0xc000
end_define

begin_define
define|#
directive|define
name|SAP_TYPE_STACK
value|0x8000
end_define

begin_define
define|#
directive|define
name|SAP_CLASS_MASK
value|0xff80
end_define

begin_define
define|#
directive|define
name|SAP_STACK
parameter_list|(
name|c
parameter_list|,
name|i
parameter_list|)
value|(SAP_TYPE_STACK | ((c)<< 7) | (i))
end_define

begin_comment
comment|/* Stack SAPs */
end_comment

begin_define
define|#
directive|define
name|SAP_ATM
value|SAP_STACK(1, 0)
end_define

begin_comment
comment|/* ATM cell */
end_comment

begin_define
define|#
directive|define
name|SAP_SAR
value|SAP_STACK(2, 0)
end_define

begin_comment
comment|/* AAL SAR */
end_comment

begin_define
define|#
directive|define
name|SAP_SAR_AAL3_4
value|SAP_STACK(2, 3)
end_define

begin_comment
comment|/* AAL3/4 SAR */
end_comment

begin_define
define|#
directive|define
name|SAP_SAR_AAL5
value|SAP_STACK(2, 5)
end_define

begin_comment
comment|/* AAL5 SAR */
end_comment

begin_define
define|#
directive|define
name|SAP_CPCS
value|SAP_STACK(3, 0)
end_define

begin_comment
comment|/* AAL CPCS */
end_comment

begin_define
define|#
directive|define
name|SAP_CPCS_AAL3_4
value|SAP_STACK(3, 3)
end_define

begin_comment
comment|/* AAL3/4 CPCS */
end_comment

begin_define
define|#
directive|define
name|SAP_CPCS_AAL5
value|SAP_STACK(3, 5)
end_define

begin_comment
comment|/* AAL5 CPCS */
end_comment

begin_define
define|#
directive|define
name|SAP_SSCOP
value|SAP_STACK(4, 0)
end_define

begin_comment
comment|/* ITU Q.2110 */
end_comment

begin_define
define|#
directive|define
name|SAP_SSCF_UNI
value|SAP_STACK(5, 0)
end_define

begin_comment
comment|/* ITU Q.2130 */
end_comment

begin_define
define|#
directive|define
name|SAP_SSCF_NNI
value|SAP_STACK(6, 0)
end_define

begin_comment
comment|/* ITU Q.2140 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_SAP_H */
end_comment

end_unit

