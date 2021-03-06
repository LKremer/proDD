% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/fit_feature_parameters.R
\name{fit_unregularized_feature_variances}
\alias{fit_unregularized_feature_variances}
\title{Find the variance without using the regularization}
\usage{
fit_unregularized_feature_variances(X, rho, zeta, experimental_design,
  upper = 1000)
}
\description{
This method is important for finding the variance prior hyperparameters.
The results are similar to the unregularized results, but I cannot reuse
those because the prior estimation needs to be unbiased from former rounds
}
\details{
The methods returns \code{NA} for each feature with less than 2 observations.
}
\keyword{internal}
