begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Machine-depend parameters for laptop machines  *  * Copyright (c) 1996, HOSOKAWA, Tatsumi<hosokawa@mt.cs.keio.ac.jp>  */
end_comment

begin_comment
comment|/*  * Laptop machines has more incompatibilities and machine-specific   * parameters than the desktop machines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LAPTOPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_LAPTOPS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LAPTOP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HINOTE
end_ifdef

begin_comment
comment|/* Digital Hinote */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_APM10
end_ifndef

begin_define
define|#
directive|define
name|COMPAT_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_APM10 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_IRQ_BUG
end_ifndef

begin_define
define|#
directive|define
name|SIO_IRQ_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIO_IRQ_BUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HINOTE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DHULTRA
end_ifdef

begin_comment
comment|/* Digital Hinote Ultra */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_APM10
end_ifndef

begin_define
define|#
directive|define
name|FORCE_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORCE_APM10 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_IRQ_BUG
end_ifndef

begin_define
define|#
directive|define
name|SIO_IRQ_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIO_IRQ_BUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DHULTRA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TP230
end_ifdef

begin_comment
comment|/* IBM ThinkPad 230 Series */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_IRQ_BUG2
end_ifndef

begin_define
define|#
directive|define
name|SIO_IRQ_BUG2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIO_IRQ_BUG2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_APM10
end_ifndef

begin_define
define|#
directive|define
name|FORCE_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORCE_APM10 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCIC_NOCLRREGS
end_ifndef

begin_define
define|#
directive|define
name|PCIC_NOCLRREGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCIC_NOCLRREGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP230 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TP230FBW
end_ifdef

begin_comment
comment|/* IBM ThinkPad 230 FBW Series */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_IRQ_BUG2
end_ifndef

begin_define
define|#
directive|define
name|SIO_IRQ_BUG2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIO_IRQ_BUG2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCIC_NOCLRREGS
end_ifndef

begin_define
define|#
directive|define
name|PCIC_NOCLRREGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCIC_NOCLRREGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP230FBW */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TP530
end_ifdef

begin_comment
comment|/* IBM ThinkPad 530 Series */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APM_DSVALUE_BUG
end_ifndef

begin_define
define|#
directive|define
name|APM_DSVALUE_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_DSVALUE_BUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP530 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINBOOKPRO
end_ifdef

begin_comment
comment|/* Sotec WinbookPro */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_APM10
end_ifndef

begin_define
define|#
directive|define
name|FORCE_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORCE_APM10 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APM_NO_ENGAGE
end_ifndef

begin_define
define|#
directive|define
name|APM_NO_ENGAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_NO_ENGAGE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APM_SUSPEND_POSTPONE
end_ifndef

begin_define
define|#
directive|define
name|APM_SUSPEND_POSTPONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_SUSPEND_POSTPONE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APM_DISABLE_BUG
end_ifndef

begin_define
define|#
directive|define
name|APM_DISABLE_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_DISABLE_BUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINBOOKPRO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GW2KLIBERTY
end_ifdef

begin_comment
comment|/* Gateway 2K Liberty */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_APM10
end_ifndef

begin_define
define|#
directive|define
name|FORCE_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORCE_APM10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GW2KLIBERTY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JETMINI
end_ifdef

begin_comment
comment|/* Panasonic Pronote Jet Mini */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_APM10
end_ifndef

begin_define
define|#
directive|define
name|FORCE_APM10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORCE_APM10 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JETMINI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONTURA
end_ifdef

begin_comment
comment|/* COMPAQ CONTURA Series */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_IRQ_BUG
end_ifndef

begin_define
define|#
directive|define
name|SIO_IRQ_BUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIO_IRQ_BUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCIC_NOCLRREGS
end_ifndef

begin_define
define|#
directive|define
name|PCIC_NOCLRREGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCIC_NOCLRREGS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APM_SUSPEND_DELAY
end_ifndef

begin_define
define|#
directive|define
name|APM_SUSPEND_DELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM_SUSPEND_DELAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONTURA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LAPTOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LAPTOPS_H_ */
end_comment

end_unit

