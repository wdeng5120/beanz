/*
    Test is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Test is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Test.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_bs_namespace {

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
    reader.add_event(0, 0, "start", "model_bs");
    reader.add_event(70, 68, "end", "model_bs");
    return reader;
}

#include <meta_header.hpp>
 class model_bs : public prob_grad {
private:
    int SIZE;
    vector_d Y;
    vector_d SIGY;
    double B;
    double D;
    double DELTA;
    int PRIORSIG;
public:
    model_bs(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_bs(stan::io::var_context& context__,
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

        static const char* function__ = "model_bs_namespace::model_bs";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 13;
            context__.validate_dims("data initialization", "SIZE", "int", context__.to_vec());
            SIZE = int(0);
            vals_i__ = context__.vals_i("SIZE");
            pos__ = 0;
            SIZE = vals_i__[pos__++];
            current_statement_begin__ = 14;
            validate_non_negative_index("Y", "SIZE", SIZE);
            context__.validate_dims("data initialization", "Y", "vector_d", context__.to_vec(SIZE));
            validate_non_negative_index("Y", "SIZE", SIZE);
            Y = vector_d(static_cast<Eigen::VectorXd::Index>(SIZE));
            vals_r__ = context__.vals_r("Y");
            pos__ = 0;
            size_t Y_i_vec_lim__ = SIZE;
            for (size_t i_vec__ = 0; i_vec__ < Y_i_vec_lim__; ++i_vec__) {
                Y[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 15;
            validate_non_negative_index("SIGY", "SIZE", SIZE);
            context__.validate_dims("data initialization", "SIGY", "vector_d", context__.to_vec(SIZE));
            validate_non_negative_index("SIGY", "SIZE", SIZE);
            SIGY = vector_d(static_cast<Eigen::VectorXd::Index>(SIZE));
            vals_r__ = context__.vals_r("SIGY");
            pos__ = 0;
            size_t SIGY_i_vec_lim__ = SIZE;
            for (size_t i_vec__ = 0; i_vec__ < SIGY_i_vec_lim__; ++i_vec__) {
                SIGY[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 16;
            context__.validate_dims("data initialization", "B", "double", context__.to_vec());
            B = double(0);
            vals_r__ = context__.vals_r("B");
            pos__ = 0;
            B = vals_r__[pos__++];
            current_statement_begin__ = 17;
            context__.validate_dims("data initialization", "D", "double", context__.to_vec());
            D = double(0);
            vals_r__ = context__.vals_r("D");
            pos__ = 0;
            D = vals_r__[pos__++];
            current_statement_begin__ = 18;
            context__.validate_dims("data initialization", "DELTA", "double", context__.to_vec());
            DELTA = double(0);
            vals_r__ = context__.vals_r("DELTA");
            pos__ = 0;
            DELTA = vals_r__[pos__++];
            current_statement_begin__ = 19;
            context__.validate_dims("data initialization", "PRIORSIG", "int", context__.to_vec());
            PRIORSIG = int(0);
            vals_i__ = context__.vals_i("PRIORSIG");
            pos__ = 0;
            PRIORSIG = vals_i__[pos__++];

            // validate, data variables
            current_statement_begin__ = 13;
            check_greater_or_equal(function__,"SIZE",SIZE,0);
            current_statement_begin__ = 14;
            current_statement_begin__ = 15;
            current_statement_begin__ = 16;
            check_greater_or_equal(function__,"B",B,0);
            current_statement_begin__ = 17;
            check_greater_or_equal(function__,"D",D,0);
            current_statement_begin__ = 18;
            check_greater_or_equal(function__,"DELTA",DELTA,0);
            current_statement_begin__ = 19;
            check_greater_or_equal(function__,"PRIORSIG",PRIORSIG,0);
            check_less_or_equal(function__,"PRIORSIG",PRIORSIG,1);
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 23;
            ++num_params_r__;
            current_statement_begin__ = 24;
            ++num_params_r__;
            current_statement_begin__ = 25;
            validate_non_negative_index("uvs", "SIZE", SIZE);
            num_params_r__ += SIZE;
            current_statement_begin__ = 26;
            validate_non_negative_index("nvs", "SIZE", SIZE);
            num_params_r__ += SIZE;
            current_statement_begin__ = 27;
            validate_non_negative_index("nphi", "SIZE", SIZE);
            num_params_r__ += SIZE;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_bs() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("b0")))
            throw std::runtime_error("variable b0 missing");
        vals_r__ = context__.vals_r("b0");
        pos__ = 0U;
        context__.validate_dims("initialization", "b0", "double", context__.to_vec());
        double b0(0);
        b0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(b0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable b0: ") + e.what());
        }

        if (!(context__.contains_r("omega")))
            throw std::runtime_error("variable omega missing");
        vals_r__ = context__.vals_r("omega");
        pos__ = 0U;
        context__.validate_dims("initialization", "omega", "double", context__.to_vec());
        double omega(0);
        omega = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,omega);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable omega: ") + e.what());
        }

        if (!(context__.contains_r("uvs")))
            throw std::runtime_error("variable uvs missing");
        vals_r__ = context__.vals_r("uvs");
        pos__ = 0U;
        validate_non_negative_index("uvs", "SIZE", SIZE);
        context__.validate_dims("initialization", "uvs", "vector_d", context__.to_vec(SIZE));
        vector_d uvs(static_cast<Eigen::VectorXd::Index>(SIZE));
        for (int j1__ = 0U; j1__ < SIZE; ++j1__)
            uvs(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lub_unconstrain(0,1,uvs);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable uvs: ") + e.what());
        }

        if (!(context__.contains_r("nvs")))
            throw std::runtime_error("variable nvs missing");
        vals_r__ = context__.vals_r("nvs");
        pos__ = 0U;
        validate_non_negative_index("nvs", "SIZE", SIZE);
        context__.validate_dims("initialization", "nvs", "vector_d", context__.to_vec(SIZE));
        vector_d nvs(static_cast<Eigen::VectorXd::Index>(SIZE));
        for (int j1__ = 0U; j1__ < SIZE; ++j1__)
            nvs(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(nvs);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable nvs: ") + e.what());
        }

        if (!(context__.contains_r("nphi")))
            throw std::runtime_error("variable nphi missing");
        vals_r__ = context__.vals_r("nphi");
        pos__ = 0U;
        validate_non_negative_index("nphi", "SIZE", SIZE);
        context__.validate_dims("initialization", "nphi", "vector_d", context__.to_vec(SIZE));
        vector_d nphi(static_cast<Eigen::VectorXd::Index>(SIZE));
        for (int j1__ = 0U; j1__ < SIZE; ++j1__)
            nphi(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(nphi);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable nphi: ") + e.what());
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

            local_scalar_t__ b0;
            (void) b0;  // dummy to suppress unused var warning
            if (jacobian__)
                b0 = in__.scalar_constrain(lp__);
            else
                b0 = in__.scalar_constrain();

            local_scalar_t__ omega;
            (void) omega;  // dummy to suppress unused var warning
            if (jacobian__)
                omega = in__.scalar_lb_constrain(0,lp__);
            else
                omega = in__.scalar_lb_constrain(0);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  uvs;
            (void) uvs;  // dummy to suppress unused var warning
            if (jacobian__)
                uvs = in__.vector_lub_constrain(0,1,SIZE,lp__);
            else
                uvs = in__.vector_lub_constrain(0,1,SIZE);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  nvs;
            (void) nvs;  // dummy to suppress unused var warning
            if (jacobian__)
                nvs = in__.vector_constrain(SIZE,lp__);
            else
                nvs = in__.vector_constrain(SIZE);

            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  nphi;
            (void) nphi;  // dummy to suppress unused var warning
            if (jacobian__)
                nphi = in__.vector_constrain(SIZE,lp__);
            else
                nphi = in__.vector_constrain(SIZE);


            // transformed parameters
            current_statement_begin__ = 31;
            validate_non_negative_index("vs", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  vs(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) vs;  // dummy to suppress unused var warning

            stan::math::initialize(vs, DUMMY_VAR__);
            stan::math::fill(vs,DUMMY_VAR__);
            current_statement_begin__ = 32;
            validate_non_negative_index("phi", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  phi(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) phi;  // dummy to suppress unused var warning

            stan::math::initialize(phi, DUMMY_VAR__);
            stan::math::fill(phi,DUMMY_VAR__);
            current_statement_begin__ = 33;
            validate_non_negative_index("mu", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  mu(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) mu;  // dummy to suppress unused var warning

            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu,DUMMY_VAR__);


            current_statement_begin__ = 35;
            if (as_bool(logical_eq(0,PRIORSIG))) {

                current_statement_begin__ = 36;
                stan::math::assign(vs, stan::math::exp(add(stan::math::log(SIGY),multiply(subtract(multiply(uvs,2),1),DELTA))));
            } else {

                current_statement_begin__ = 38;
                stan::math::assign(vs, stan::math::exp(add(stan::math::log(SIGY),multiply(nvs,stan::math::sqrt(DELTA)))));
            }
            current_statement_begin__ = 42;
            stan::math::assign(phi, multiply(nphi,omega));
            current_statement_begin__ = 43;
            stan::math::assign(mu, add(b0,phi));

            // validate transformed parameters
            for (int i0__ = 0; i0__ < SIZE; ++i0__) {
                if (stan::math::is_uninitialized(vs(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: vs" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            for (int i0__ = 0; i0__ < SIZE; ++i0__) {
                if (stan::math::is_uninitialized(phi(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: phi" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            for (int i0__ = 0; i0__ < SIZE; ++i0__) {
                if (stan::math::is_uninitialized(mu(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: mu" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 31;
            check_greater_or_equal(function__,"vs",vs,0);
            current_statement_begin__ = 32;
            current_statement_begin__ = 33;

            // model body

            current_statement_begin__ = 47;
            lp_accum__.add(normal_log<propto__>(b0, 0, stan::math::sqrt(B)));
            current_statement_begin__ = 48;
            lp_accum__.add(normal_log<propto__>(nphi, 0, 1));
            current_statement_begin__ = 49;
            lp_accum__.add(uniform_log<propto__>(uvs, 0, 1));
            current_statement_begin__ = 50;
            lp_accum__.add(normal_log<propto__>(nvs, 0, 1));
            current_statement_begin__ = 52;
            if (as_bool(logical_eq(0,D))) {

                current_statement_begin__ = 54;
                lp_accum__.add(-(stan::math::log(omega)));
            } else {

                current_statement_begin__ = 57;
                lp_accum__.add(normal_log<propto__>(omega, 0, stan::math::sqrt(D)));
            }
            current_statement_begin__ = 60;
            lp_accum__.add(normal_log<propto__>(Y, mu, vs));

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
        names__.push_back("b0");
        names__.push_back("omega");
        names__.push_back("uvs");
        names__.push_back("nvs");
        names__.push_back("nphi");
        names__.push_back("vs");
        names__.push_back("phi");
        names__.push_back("mu");
        names__.push_back("log_lik");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(SIZE);
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
        static const char* function__ = "model_bs_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double b0 = in__.scalar_constrain();
        double omega = in__.scalar_lb_constrain(0);
        vector_d uvs = in__.vector_lub_constrain(0,1,SIZE);
        vector_d nvs = in__.vector_constrain(SIZE);
        vector_d nphi = in__.vector_constrain(SIZE);
        vars__.push_back(b0);
        vars__.push_back(omega);
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(uvs[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(nvs[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(nphi[k_0__]);
            }

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 31;
            validate_non_negative_index("vs", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  vs(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) vs;  // dummy to suppress unused var warning

            stan::math::initialize(vs, DUMMY_VAR__);
            stan::math::fill(vs,DUMMY_VAR__);
            current_statement_begin__ = 32;
            validate_non_negative_index("phi", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  phi(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) phi;  // dummy to suppress unused var warning

            stan::math::initialize(phi, DUMMY_VAR__);
            stan::math::fill(phi,DUMMY_VAR__);
            current_statement_begin__ = 33;
            validate_non_negative_index("mu", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  mu(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) mu;  // dummy to suppress unused var warning

            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu,DUMMY_VAR__);


            current_statement_begin__ = 35;
            if (as_bool(logical_eq(0,PRIORSIG))) {

                current_statement_begin__ = 36;
                stan::math::assign(vs, stan::math::exp(add(stan::math::log(SIGY),multiply(subtract(multiply(uvs,2),1),DELTA))));
            } else {

                current_statement_begin__ = 38;
                stan::math::assign(vs, stan::math::exp(add(stan::math::log(SIGY),multiply(nvs,stan::math::sqrt(DELTA)))));
            }
            current_statement_begin__ = 42;
            stan::math::assign(phi, multiply(nphi,omega));
            current_statement_begin__ = 43;
            stan::math::assign(mu, add(b0,phi));

            // validate transformed parameters
            current_statement_begin__ = 31;
            check_greater_or_equal(function__,"vs",vs,0);
            current_statement_begin__ = 32;
            current_statement_begin__ = 33;

            // write transformed parameters
            if (include_tparams__) {
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(vs[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(phi[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(mu[k_0__]);
            }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 64;
            validate_non_negative_index("log_lik", "SIZE", SIZE);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  log_lik(static_cast<Eigen::VectorXd::Index>(SIZE));
            (void) log_lik;  // dummy to suppress unused var warning

            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik,DUMMY_VAR__);


            current_statement_begin__ = 65;
            for (int i = 1; i <= SIZE; ++i) {

                current_statement_begin__ = 66;
                stan::model::assign(log_lik, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            normal_log(get_base1(Y,i,"Y",1),get_base1(mu,i,"mu",1),get_base1(vs,i,"vs",1)), 
                            "assigning variable log_lik");
            }

            // validate generated quantities
            current_statement_begin__ = 64;

            // write generated quantities
            for (int k_0__ = 0; k_0__ < SIZE; ++k_0__) {
            vars__.push_back(log_lik[k_0__]);
            }

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
        return "model_bs";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "b0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "omega";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "uvs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nvs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nphi" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "vs" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "phi" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "mu" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "b0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "omega";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "uvs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nvs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nphi" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "vs" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "phi" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "mu" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
        for (int k_0__ = 1; k_0__ <= SIZE; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }

}; // model

}

typedef model_bs_namespace::model_bs stan_model;


#endif
