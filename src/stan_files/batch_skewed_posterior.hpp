/*
    skewedposteriorstanwrapper is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    skewedposteriorstanwrapper is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with skewedposteriorstanwrapper.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_batch_skewed_posterior_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_batch_skewed_posterior");
    reader.add_event(53, 51, "end", "model_batch_skewed_posterior");
    return reader;
}

#include <meta_header.hpp>
 class model_batch_skewed_posterior : public prob_grad {
private:
    int nsamples;
    int nrows;
    int totalmissing;
    matrix_d X;
    vector<double> zeta;
    vector<double> rho;
    double mu0;
    double sigma20;
    double eta;
    double nu;
public:
    model_batch_skewed_posterior(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_batch_skewed_posterior(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_batch_skewed_posterior_namespace::model_batch_skewed_posterior";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "nsamples", "int", context__.to_vec());
            nsamples = int(0);
            vals_i__ = context__.vals_i("nsamples");
            pos__ = 0;
            nsamples = vals_i__[pos__++];
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "nrows", "int", context__.to_vec());
            nrows = int(0);
            vals_i__ = context__.vals_i("nrows");
            pos__ = 0;
            nrows = vals_i__[pos__++];
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "totalmissing", "int", context__.to_vec());
            totalmissing = int(0);
            vals_i__ = context__.vals_i("totalmissing");
            pos__ = 0;
            totalmissing = vals_i__[pos__++];
            current_statement_begin__ = 5;
            validate_non_negative_index("X", "nrows", nrows);
            validate_non_negative_index("X", "nsamples", nsamples);
            context__.validate_dims("data initialization", "X", "matrix_d", context__.to_vec(nrows,nsamples));
            validate_non_negative_index("X", "nrows", nrows);
            validate_non_negative_index("X", "nsamples", nsamples);
            X = matrix_d(static_cast<Eigen::VectorXd::Index>(nrows),static_cast<Eigen::VectorXd::Index>(nsamples));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_m_mat_lim__ = nrows;
            size_t X_n_mat_lim__ = nsamples;
            for (size_t n_mat__ = 0; n_mat__ < X_n_mat_lim__; ++n_mat__) {
                for (size_t m_mat__ = 0; m_mat__ < X_m_mat_lim__; ++m_mat__) {
                    X(m_mat__,n_mat__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 7;
            validate_non_negative_index("zeta", "nsamples", nsamples);
            context__.validate_dims("data initialization", "zeta", "double", context__.to_vec(nsamples));
            validate_non_negative_index("zeta", "nsamples", nsamples);
            zeta = std::vector<double>(nsamples,double(0));
            vals_r__ = context__.vals_r("zeta");
            pos__ = 0;
            size_t zeta_limit_0__ = nsamples;
            for (size_t i_0__ = 0; i_0__ < zeta_limit_0__; ++i_0__) {
                zeta[i_0__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 8;
            validate_non_negative_index("rho", "nsamples", nsamples);
            context__.validate_dims("data initialization", "rho", "double", context__.to_vec(nsamples));
            validate_non_negative_index("rho", "nsamples", nsamples);
            rho = std::vector<double>(nsamples,double(0));
            vals_r__ = context__.vals_r("rho");
            pos__ = 0;
            size_t rho_limit_0__ = nsamples;
            for (size_t i_0__ = 0; i_0__ < rho_limit_0__; ++i_0__) {
                rho[i_0__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "mu0", "double", context__.to_vec());
            mu0 = double(0);
            vals_r__ = context__.vals_r("mu0");
            pos__ = 0;
            mu0 = vals_r__[pos__++];
            current_statement_begin__ = 10;
            context__.validate_dims("data initialization", "sigma20", "double", context__.to_vec());
            sigma20 = double(0);
            vals_r__ = context__.vals_r("sigma20");
            pos__ = 0;
            sigma20 = vals_r__[pos__++];
            current_statement_begin__ = 11;
            context__.validate_dims("data initialization", "eta", "double", context__.to_vec());
            eta = double(0);
            vals_r__ = context__.vals_r("eta");
            pos__ = 0;
            eta = vals_r__[pos__++];
            current_statement_begin__ = 12;
            context__.validate_dims("data initialization", "nu", "double", context__.to_vec());
            nu = double(0);
            vals_r__ = context__.vals_r("nu");
            pos__ = 0;
            nu = vals_r__[pos__++];

            // validate, data variables
            current_statement_begin__ = 2;
            current_statement_begin__ = 3;
            current_statement_begin__ = 4;
            current_statement_begin__ = 5;
            current_statement_begin__ = 7;
            current_statement_begin__ = 8;
            current_statement_begin__ = 9;
            current_statement_begin__ = 10;
            current_statement_begin__ = 11;
            current_statement_begin__ = 12;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 15;
            validate_non_negative_index("mu", "nrows", nrows);
            num_params_r__ += nrows;
            current_statement_begin__ = 16;
            validate_non_negative_index("sigma", "nrows", nrows);
            num_params_r__ += nrows;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_batch_skewed_posterior() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("mu")))
            throw std::runtime_error("variable mu missing");
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        validate_non_negative_index("mu", "nrows", nrows);
        context__.validate_dims("initialization", "mu", "double", context__.to_vec(nrows));
        std::vector<double> mu(nrows,double(0));
        for (int i0__ = 0U; i0__ < nrows; ++i0__)
            mu[i0__] = vals_r__[pos__++];
        for (int i0__ = 0U; i0__ < nrows; ++i0__)
            try {
            writer__.scalar_unconstrain(mu[i0__]);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        validate_non_negative_index("sigma", "nrows", nrows);
        context__.validate_dims("initialization", "sigma", "double", context__.to_vec(nrows));
        std::vector<double> sigma(nrows,double(0));
        for (int i0__ = 0U; i0__ < nrows; ++i0__)
            sigma[i0__] = vals_r__[pos__++];
        for (int i0__ = 0U; i0__ < nrows; ++i0__)
            try {
            writer__.scalar_lb_unconstrain(0,sigma[i0__]);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            vector<local_scalar_t__> mu;
            size_t dim_mu_0__ = nrows;
            mu.reserve(dim_mu_0__);
            for (size_t k_0__ = 0; k_0__ < dim_mu_0__; ++k_0__) {
                if (jacobian__)
                    mu.push_back(in__.scalar_constrain(lp__));
                else
                    mu.push_back(in__.scalar_constrain());
            }

            vector<local_scalar_t__> sigma;
            size_t dim_sigma_0__ = nrows;
            sigma.reserve(dim_sigma_0__);
            for (size_t k_0__ = 0; k_0__ < dim_sigma_0__; ++k_0__) {
                if (jacobian__)
                    sigma.push_back(in__.scalar_lb_constrain(0,lp__));
                else
                    sigma.push_back(in__.scalar_lb_constrain(0));
            }


            // transformed parameters
            current_statement_begin__ = 19;
            validate_non_negative_index("sigma2", "nrows", nrows);
            vector<local_scalar_t__> sigma2(nrows);
            stan::math::initialize(sigma2, DUMMY_VAR__);
            stan::math::fill(sigma2,DUMMY_VAR__);
            current_statement_begin__ = 20;
            validate_non_negative_index("zetastar", "totalmissing", totalmissing);
            vector<local_scalar_t__> zetastar(totalmissing);
            stan::math::initialize(zetastar, DUMMY_VAR__);
            stan::math::fill(zetastar,DUMMY_VAR__);


            {
            current_statement_begin__ = 22;
            int counter(0);
            (void) counter;  // dummy to suppress unused var warning

            stan::math::fill(counter, std::numeric_limits<int>::min());
            stan::math::assign(counter,1);


            current_statement_begin__ = 23;
            for (int i = 1; i <= nrows; ++i) {

                current_statement_begin__ = 24;
                stan::model::assign(sigma2, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            pow(get_base1(sigma,i,"sigma",1),2), 
                            "assigning variable sigma2");
                current_statement_begin__ = 25;
                for (int j = 1; j <= nsamples; ++j) {

                    current_statement_begin__ = 26;
                    if (as_bool(is_inf(get_base1(X,i,j,"X",1)))) {

                        current_statement_begin__ = 27;
                        stan::model::assign(zetastar, 
                                    stan::model::cons_list(stan::model::index_uni(counter), stan::model::nil_index_list()), 
                                    (get_base1(zeta,j,"zeta",1) * stan::math::sqrt((1 + (get_base1(sigma2,i,"sigma2",1) / pow(get_base1(zeta,j,"zeta",1),2))))), 
                                    "assigning variable zetastar");
                        current_statement_begin__ = 28;
                        stan::math::assign(counter, stan::model::deep_copy((counter + 1)));
                    }
                }
            }
            }

            // validate transformed parameters
            for (int i0__ = 0; i0__ < nrows; ++i0__) {
                if (stan::math::is_uninitialized(sigma2[i0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: sigma2" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            for (int i0__ = 0; i0__ < totalmissing; ++i0__) {
                if (stan::math::is_uninitialized(zetastar[i0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: zetastar" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 19;
            current_statement_begin__ = 20;

            // model body

            current_statement_begin__ = 35;
            lp_accum__.add(normal_log<propto__>(mu, mu0, stan::math::sqrt(sigma20)));
            current_statement_begin__ = 36;
            lp_accum__.add(scaled_inv_chi_square_log<propto__>(sigma2, nu, stan::math::sqrt(eta)));
            {
            current_statement_begin__ = 38;
            int counter(0);
            (void) counter;  // dummy to suppress unused var warning

            stan::math::fill(counter, std::numeric_limits<int>::min());
            stan::math::assign(counter,1);


            current_statement_begin__ = 39;
            for (int i = 1; i <= nrows; ++i) {

                current_statement_begin__ = 40;
                for (int j = 1; j <= nsamples; ++j) {

                    current_statement_begin__ = 41;
                    if (as_bool(is_inf(get_base1(X,i,j,"X",1)))) {

                        current_statement_begin__ = 42;
                        lp_accum__.add(normal_ccdf_log(get_base1(mu,i,"mu",1),get_base1(rho,j,"rho",1),stan::math::fabs(get_base1(zetastar,counter,"zetastar",1))));
                        current_statement_begin__ = 43;
                        stan::math::assign(counter, (counter + 1));
                    } else {

                        current_statement_begin__ = 45;
                        lp_accum__.add(normal_log<propto__>(get_base1(X,i,j,"X",1), get_base1(mu,i,"mu",1), get_base1(sigma,i,"sigma",1)));
                    }
                }
            }
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("sigma");
        names__.push_back("sigma2");
        names__.push_back("zetastar");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(nrows);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(nrows);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(nrows);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(totalmissing);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_batch_skewed_posterior_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector<double> mu;
        size_t dim_mu_0__ = nrows;
        for (size_t k_0__ = 0; k_0__ < dim_mu_0__; ++k_0__) {
            mu.push_back(in__.scalar_constrain());
        }
        vector<double> sigma;
        size_t dim_sigma_0__ = nrows;
        for (size_t k_0__ = 0; k_0__ < dim_sigma_0__; ++k_0__) {
            sigma.push_back(in__.scalar_lb_constrain(0));
        }
            for (int k_0__ = 0; k_0__ < nrows; ++k_0__) {
            vars__.push_back(mu[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < nrows; ++k_0__) {
            vars__.push_back(sigma[k_0__]);
            }

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 19;
            validate_non_negative_index("sigma2", "nrows", nrows);
            vector<local_scalar_t__> sigma2(nrows);
            stan::math::initialize(sigma2, DUMMY_VAR__);
            stan::math::fill(sigma2,DUMMY_VAR__);
            current_statement_begin__ = 20;
            validate_non_negative_index("zetastar", "totalmissing", totalmissing);
            vector<local_scalar_t__> zetastar(totalmissing);
            stan::math::initialize(zetastar, DUMMY_VAR__);
            stan::math::fill(zetastar,DUMMY_VAR__);


            {
            current_statement_begin__ = 22;
            int counter(0);
            (void) counter;  // dummy to suppress unused var warning

            stan::math::fill(counter, std::numeric_limits<int>::min());
            stan::math::assign(counter,1);


            current_statement_begin__ = 23;
            for (int i = 1; i <= nrows; ++i) {

                current_statement_begin__ = 24;
                stan::model::assign(sigma2, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            pow(get_base1(sigma,i,"sigma",1),2), 
                            "assigning variable sigma2");
                current_statement_begin__ = 25;
                for (int j = 1; j <= nsamples; ++j) {

                    current_statement_begin__ = 26;
                    if (as_bool(is_inf(get_base1(X,i,j,"X",1)))) {

                        current_statement_begin__ = 27;
                        stan::model::assign(zetastar, 
                                    stan::model::cons_list(stan::model::index_uni(counter), stan::model::nil_index_list()), 
                                    (get_base1(zeta,j,"zeta",1) * stan::math::sqrt((1 + (get_base1(sigma2,i,"sigma2",1) / pow(get_base1(zeta,j,"zeta",1),2))))), 
                                    "assigning variable zetastar");
                        current_statement_begin__ = 28;
                        stan::math::assign(counter, stan::model::deep_copy((counter + 1)));
                    }
                }
            }
            }

            // validate transformed parameters
            current_statement_begin__ = 19;
            current_statement_begin__ = 20;

            // write transformed parameters
            if (include_tparams__) {
            for (int k_0__ = 0; k_0__ < nrows; ++k_0__) {
            vars__.push_back(sigma2[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < totalmissing; ++k_0__) {
            vars__.push_back(zetastar[k_0__]);
            }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_batch_skewed_posterior";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sigma2" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= totalmissing; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "zetastar" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "sigma" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= nrows; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "sigma2" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= totalmissing; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "zetastar" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_batch_skewed_posterior_namespace::model_batch_skewed_posterior stan_model;


#endif