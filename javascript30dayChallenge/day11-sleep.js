const sleep = async (milis) => {
    await new Promise((resolve) => setTimeout(resolve, milis))
}

const sleep2 = (millis) => new Promise((resolve, reject) => setTimeout(resolve, millis));