% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/fit_hyperparameters.R
\name{fit_parameters}
\alias{fit_parameters}
\title{Fit the probabilistic dropout parameters}
\usage{
fit_parameters(X, experimental_design, dropout_curve_calc = c("sample",
  "global_scale", "global"), frac_subsample = 1,
  n_subsample = round(nrow(X) * frac_subsample), max_iter = 10,
  epsilon = 0.001, verbose = FALSE)
}
\arguments{
\item{X}{the numerical data where each column is one sample and each row
is one protein. Missing values are coded as \code{NA}.}

\item{experimental_design}{a vector that assignes each sample to one condition.
It has the same length as the number of columns in \code{X}. It can either be
a factor, a character or a numeric vector. Each unique element is one condition.}

\item{dropout_curve_calc}{string that specifies how the dropout curves are
estimated. There are three different modes. "sample": number of curves=
number of samples, "global": number of curves=1, "global_scale": estimate
only a single scale of the sigmoid, but estimate the position per sample.
Default: "sample".}

\item{frac_subsample}{number between 0 and 1. Often it is not necessary to
consider each protein, but the computation can be significantly sped up
by only considering a subset of the subsets. Default: 1.0.}

\item{n_subsample}{number between 1 and \code{nrow(X)}. Alternative way to
specify how many proteins are considered for estimating the hyper-parameters.
Default: \code{nrow(X) * frac_subsample}.}

\item{max_iter}{integer larger than 1. How many iterations are run at most
trying to reach convergence. Default: 10.}

\item{epsilon}{number larger than 0. How big is the maximum remaining error
for the algorithm to be considered converged. Default: 10^-3}

\item{verbose}{boolean. Specify how much extra information is printed
while the algorithm is running. Default: \code{FALSE}.}
}
\value{
a list containing the infered parameters. The list is tagged
  with the class "prodd_parameters" for simpler handling in downstream
  methods
}
\description{
The method infers the position and scale of the dropout sigmoids, the
location prior of the means and the prior for the variance. In addition it
estimates some feature parameters (mean, uncertainty of mean and variance
for each protein and condition).
}
