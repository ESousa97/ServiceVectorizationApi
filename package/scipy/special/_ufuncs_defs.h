#ifndef UFUNCS_PROTO_H
#define UFUNCS_PROTO_H 1
#include "_cosine.h"
npy_double cosine_cdf(npy_double);
npy_double cosine_invcdf(npy_double);
#include "cephes.h"
npy_double cospi(npy_double);
npy_double igam_fac(npy_double, npy_double);
npy_double kolmogc(npy_double);
npy_double kolmogci(npy_double);
npy_double kolmogp(npy_double);
npy_double lanczos_sum_expg_scaled(npy_double);
npy_double lgam1p(npy_double);
npy_double log1pmx(npy_double);
npy_double riemann_zeta(npy_double);
#include "scaled_exp1.h"
npy_double scaled_exp1(npy_double);
npy_double sinpi(npy_double);
npy_double smirnovc(npy_int, npy_double);
npy_double smirnovci(npy_int, npy_double);
npy_double smirnovp(npy_int, npy_double);
npy_double struve_asymp_large_z(npy_double, npy_double, npy_int, npy_double *);
npy_double struve_bessel_series(npy_double, npy_double, npy_int, npy_double *);
npy_double struve_power_series(npy_double, npy_double, npy_int, npy_double *);
npy_double zeta(npy_double, npy_double);
#include "amos_wrappers.h"
npy_int airy_wrap(npy_double, npy_double *, npy_double *, npy_double *, npy_double *);
npy_int cairy_wrap(npy_cdouble, npy_cdouble *, npy_cdouble *, npy_cdouble *, npy_cdouble *);
npy_int cairy_wrap_e(npy_cdouble, npy_cdouble *, npy_cdouble *, npy_cdouble *, npy_cdouble *);
npy_int cairy_wrap_e_real(npy_double, npy_double *, npy_double *, npy_double *, npy_double *);
npy_double bdtr(npy_double, npy_int, npy_double);
npy_double bdtrc(npy_double, npy_int, npy_double);
npy_double bdtri(npy_double, npy_int, npy_double);
#include "specfun_wrappers.h"
npy_double bei_wrap(npy_double);
npy_double beip_wrap(npy_double);
npy_double ber_wrap(npy_double);
npy_double berp_wrap(npy_double);
npy_double besselpoly(npy_double, npy_double, npy_double);
npy_double beta(npy_double, npy_double);
npy_double lbeta(npy_double, npy_double);
npy_double btdtr(npy_double, npy_double, npy_double);
npy_double incbi(npy_double, npy_double, npy_double);
npy_double cbrt(npy_double);
npy_double chdtr(npy_double, npy_double);
npy_double chdtrc(npy_double, npy_double);
npy_double chdtri(npy_double, npy_double);
npy_double cosdg(npy_double);
npy_double cosm1(npy_double);
npy_double cotdg(npy_double);
npy_double ellpe(npy_double);
npy_double ellie(npy_double, npy_double);
npy_int ellpj(npy_double, npy_double, npy_double *, npy_double *, npy_double *, npy_double *);
npy_double ellik(npy_double, npy_double);
npy_double ellpk(npy_double);
npy_double erf(npy_double);
npy_double erfc(npy_double);
npy_double erfcinv(npy_double);
npy_cdouble cexp1_wrap(npy_cdouble);
npy_double exp1_wrap(npy_double);
npy_double exp10(npy_double);
npy_double exp2(npy_double);
npy_cdouble cexpi_wrap(npy_cdouble);
npy_double expi_wrap(npy_double);
npy_double expm1(npy_double);
npy_double expn(npy_int, npy_double);
npy_double fdtr(npy_double, npy_double, npy_double);
npy_double fdtrc(npy_double, npy_double, npy_double);
npy_double fdtri(npy_double, npy_double, npy_double);
npy_int fresnl(npy_double, npy_double *, npy_double *);
npy_int cfresnl_wrap(npy_cdouble, npy_cdouble *, npy_cdouble *);
npy_double Gamma(npy_double);
npy_double igam(npy_double, npy_double);
npy_double igamc(npy_double, npy_double);
npy_double igamci(npy_double, npy_double);
npy_double igami(npy_double, npy_double);
npy_double lgam(npy_double);
npy_double gammasgn(npy_double);
npy_double gdtr(npy_double, npy_double, npy_double);
npy_double gdtrc(npy_double, npy_double, npy_double);
npy_cdouble cbesh_wrap1(npy_double, npy_cdouble);
npy_cdouble cbesh_wrap1_e(npy_double, npy_cdouble);
npy_cdouble cbesh_wrap2(npy_double, npy_cdouble);
npy_cdouble cbesh_wrap2_e(npy_double, npy_cdouble);
npy_cdouble chyp1f1_wrap(npy_double, npy_double, npy_cdouble);
npy_double hyp2f1(npy_double, npy_double, npy_double, npy_double);
npy_double i0(npy_double);
npy_double i0e(npy_double);
npy_double i1(npy_double);
npy_double i1e(npy_double);
npy_int it2i0k0_wrap(npy_double, npy_double *, npy_double *);
npy_int it2j0y0_wrap(npy_double, npy_double *, npy_double *);
npy_double it2struve0_wrap(npy_double);
npy_int itairy_wrap(npy_double, npy_double *, npy_double *, npy_double *, npy_double *);
npy_int it1i0k0_wrap(npy_double, npy_double *, npy_double *);
npy_int it1j0y0_wrap(npy_double, npy_double *, npy_double *);
npy_double itmodstruve0_wrap(npy_double);
npy_double itstruve0_wrap(npy_double);
npy_cdouble cbesi_wrap(npy_double, npy_cdouble);
npy_double iv(npy_double, npy_double);
npy_cdouble cbesi_wrap_e(npy_double, npy_cdouble);
npy_double cbesi_wrap_e_real(npy_double, npy_double);
npy_double j0(npy_double);
npy_double j1(npy_double);
npy_cdouble cbesj_wrap(npy_double, npy_cdouble);
npy_double cbesj_wrap_real(npy_double, npy_double);
npy_cdouble cbesj_wrap_e(npy_double, npy_cdouble);
npy_double cbesj_wrap_e_real(npy_double, npy_double);
npy_double k0(npy_double);
npy_double k0e(npy_double);
npy_double k1(npy_double);
npy_double k1e(npy_double);
npy_double kei_wrap(npy_double);
npy_double keip_wrap(npy_double);
npy_int kelvin_wrap(npy_double, npy_cdouble *, npy_cdouble *, npy_cdouble *, npy_cdouble *);
npy_double ker_wrap(npy_double);
npy_double kerp_wrap(npy_double);
npy_double cbesk_wrap_real_int(npy_int, npy_double);
npy_double kolmogi(npy_double);
npy_double kolmogorov(npy_double);
npy_cdouble cbesk_wrap(npy_double, npy_cdouble);
npy_double cbesk_wrap_real(npy_double, npy_double);
npy_cdouble cbesk_wrap_e(npy_double, npy_cdouble);
npy_double cbesk_wrap_e_real(npy_double, npy_double);
npy_double log1p(npy_double);
npy_double pmv_wrap(npy_double, npy_double, npy_double);
npy_double cem_cva_wrap(npy_double, npy_double);
npy_double sem_cva_wrap(npy_double, npy_double);
npy_int cem_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int mcm1_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int mcm2_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int msm1_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int msm2_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int sem_wrap(npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_int modified_fresnel_minus_wrap(npy_double, npy_cdouble *, npy_cdouble *);
npy_int modified_fresnel_plus_wrap(npy_double, npy_cdouble *, npy_cdouble *);
npy_double struve_l(npy_double, npy_double);
npy_double nbdtr(npy_int, npy_int, npy_double);
npy_double nbdtrc(npy_int, npy_int, npy_double);
npy_double nbdtri(npy_int, npy_int, npy_double);
npy_double ndtr(npy_double);
npy_double ndtri(npy_double);
npy_double oblate_aswfa_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int oblate_aswfa_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double oblate_segv_wrap(npy_double, npy_double, npy_double);
npy_double oblate_radial1_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int oblate_radial1_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double oblate_radial2_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int oblate_radial2_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double owens_t(npy_double, npy_double);
npy_int pbdv_wrap(npy_double, npy_double, npy_double *, npy_double *);
npy_int pbvv_wrap(npy_double, npy_double, npy_double *, npy_double *);
npy_int pbwa_wrap(npy_double, npy_double, npy_double *, npy_double *);
npy_double pdtr(npy_double, npy_double);
npy_double pdtrc(npy_double, npy_double);
npy_double pdtri(npy_int, npy_double);
npy_double poch(npy_double, npy_double);
npy_double prolate_aswfa_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int prolate_aswfa_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double prolate_segv_wrap(npy_double, npy_double, npy_double);
npy_double prolate_radial1_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int prolate_radial1_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double prolate_radial2_nocv_wrap(npy_double, npy_double, npy_double, npy_double, npy_double *);
npy_int prolate_radial2_wrap(npy_double, npy_double, npy_double, npy_double, npy_double, npy_double *, npy_double *);
npy_double radian(npy_double, npy_double, npy_double);
npy_double rgamma(npy_double);
npy_double round(npy_double);
npy_int shichi(npy_double, npy_double *, npy_double *);
npy_int sici(npy_double, npy_double *, npy_double *);
npy_double sindg(npy_double);
npy_double smirnov(npy_int, npy_double);
npy_double smirnovi(npy_int, npy_double);
npy_double spence(npy_double);
npy_double struve_h(npy_double, npy_double);
npy_double tandg(npy_double);
npy_double tukeylambdacdf(npy_double, npy_double);
npy_double y0(npy_double);
npy_double y1(npy_double);
npy_double yn(npy_int, npy_double);
npy_cdouble cbesy_wrap(npy_double, npy_cdouble);
npy_double cbesy_wrap_real(npy_double, npy_double);
npy_cdouble cbesy_wrap_e(npy_double, npy_cdouble);
npy_double cbesy_wrap_e_real(npy_double, npy_double);
npy_double zetac(npy_double);
#endif
