import styles from 'styles/login/login.module.css';

function Login() {
  return (
    <div className={styles.loginContainer}>
      <div className={styles.innerContainer}>
        <div className={styles.title}>{'ft_transcendence'}</div>
        <a
          href={`${process.env.REACT_APP_SERVERIP}/oauth/42`}
          style={{ textDecoration: 'none' }}
        >
          <input type='button' className={styles.buttons} value='로그인' />
        </a>
      </div>
    </div>
  );
}

export default Login;
