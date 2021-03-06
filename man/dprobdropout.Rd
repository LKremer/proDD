% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/probabilistic_dropouts.R
\name{dprobdropout}
\alias{dprobdropout}
\title{Density of the probabilistic dropout distribution}
\usage{
dprobdropout(x, mu, sigma2, rho = numeric(0), zeta = numeric(0),
  nmis = length(rho), log = FALSE)
}
\arguments{
\item{x}{vector of input positions.}

\item{mu}{double. The mean of the observed values.}

\item{sigma2}{double. The variance of the mu estimate.}

\item{rho}{vector. The positions of the inflection points of the dropout
curves for each sample. Can also be a single number that is repeated
\code{nmis} times. Defaults to an empty vector.}

\item{zeta}{vector.  The scale of the dropout curves for each sample.
Can also be a single number that is repeated \code{nmis} times.
Defaults to an empty vector.}

\item{nmis}{integer The number of missing values.
Defaults to \code{length(rho)}.}

\item{log}{boolean if the log of the density is returned.}
}
\description{
Calculate the density under a censoring mechanism that probabilistically
causes dropouts described with \code{rho} and \code{zeta}. The data is drawn
from a normal with \code{mu} and \code{sigma2 * nobs}, but each value drops out with
probability according to a inverse probit with its center at \code{rho} and width
\code{zeta}:
\deqn{
  p(x | \mu, \sigma^2, \rho, \zeta) \propto f_{\text{Normal}}(x;\mu, \sigma^2)
       \prod_i f_{\Phi}(x; \rho_i, \zeta_i)
}{
  p(x | \mu, \sigma2, \rho, \zeta) ~ Normal(x; \mu, \sigma2) Prod_i \Phi(x; \rho_i, \zeta_i)
}
The distribution is related to the extended skewed normal distribution
and formally belongs to the class of closed skewed normals.
}
\examples{
  xg <- seq(-5, 5, length.out=101)
  plot(xg, dprobdropout(xg, mu=0, sigma2=3, rho=0, zeta=1))

}
\references{
1. Azzalini, A. & Capitanio, A. The Skew-Normal and Related Families.
    (Cambridge University Press, 2013). doi:10.1017/CBO97811392488911.

  2. González-Farías, G., Domínguez-Molina, A. & Gupta, A. K.
    Additive properties of skew normal random vectors.
    J. Stat. Plan. Inference 126, 521–534 (2004).
    doi:10.1016/j.jspi.2003.09.008
}
