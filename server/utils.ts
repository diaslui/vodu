type logtype = "info" | "warn" | "error";

export const log = (message: string, type: logtype, context: string) => {
    const devMode = process.env.NODE_ENV !== "production";
    if (!devMode) return;
    console.log(`[${new Date().toISOString()} | ${type.toUpperCase()}]: ${message} (${context})`);
};